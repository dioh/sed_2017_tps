#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WagesCtop.h"

using namespace std;

WagesCtop::WagesCtop(const string &name) :
	Atomic(name),
    in_port_wSValue(addInputPort("in_port_wSValue")),
    in_port_YCValue(addInputPort("in_port_YCValue")),
    isSet_wSValue(false),
    isSet_YCValue(false),
	out_port_WagesC(addOutputPort("out_port_WagesC"))
{
}


Model &WagesCtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WagesCtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_wSValue) {
		wSValue = x;
		isSet_wSValue = true;
	}
	if(msg.port() == in_port_YCValue) {
		YCValue = x;
		isSet_YCValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WagesCtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WagesCtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_wSValue & isSet_YCValue ) {
	    Tuple<Real> out_value { (YCValue*wSValue) };
		sendOutput(msg.time(), out_port_WagesC, out_value);
	}
	
	return *this ;
}