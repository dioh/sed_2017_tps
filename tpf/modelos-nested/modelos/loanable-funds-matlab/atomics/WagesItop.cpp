#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WagesItop.h"

using namespace std;

WagesItop::WagesItop(const string &name) :
	Atomic(name),
    in_port_wSValue(addInputPort("in_port_wSValue")),
    in_port_YIValue(addInputPort("in_port_YIValue")),
    isSet_wSValue(false),
    isSet_YIValue(false),
	out_port_WagesI(addOutputPort("out_port_WagesI"))
{
}


Model &WagesItop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WagesItop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_wSValue) {
		wSValue = x;
		isSet_wSValue = true;
	}
	if(msg.port() == in_port_YIValue) {
		YIValue = x;
		isSet_YIValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WagesItop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WagesItop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_wSValue & isSet_YIValue ) {
	    Tuple<Real> out_value { (YIValue*wSValue) };
		sendOutput(msg.time(), out_port_WagesI, out_value);
	}
	
	return *this ;
}