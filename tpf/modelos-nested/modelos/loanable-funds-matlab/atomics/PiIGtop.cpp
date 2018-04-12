#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PiIGtop.h"

using namespace std;

PiIGtop::PiIGtop(const string &name) :
	Atomic(name),
    in_port_YIValue(addInputPort("in_port_YIValue")),
    in_port_WagesI(addInputPort("in_port_WagesI")),
    isSet_YIValue(false),
    isSet_WagesI(false),
	out_port_PiIG(addOutputPort("out_port_PiIG"))
{
}


Model &PiIGtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PiIGtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_YIValue) {
		YIValue = x;
		isSet_YIValue = true;
	}
	if(msg.port() == in_port_WagesI) {
		WagesI = x;
		isSet_WagesI = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PiIGtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PiIGtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_YIValue & isSet_WagesI ) {
	    Tuple<Real> out_value { (YIValue-WagesI) };
		sendOutput(msg.time(), out_port_PiIG, out_value);
	}
	
	return *this ;
}