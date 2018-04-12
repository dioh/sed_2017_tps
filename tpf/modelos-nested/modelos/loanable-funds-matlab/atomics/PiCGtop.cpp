#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PiCGtop.h"

using namespace std;

PiCGtop::PiCGtop(const string &name) :
	Atomic(name),
    in_port_YCValue(addInputPort("in_port_YCValue")),
    in_port_WagesC(addInputPort("in_port_WagesC")),
    isSet_YCValue(false),
    isSet_WagesC(false),
	out_port_PiCG(addOutputPort("out_port_PiCG"))
{
}


Model &PiCGtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PiCGtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_YCValue) {
		YCValue = x;
		isSet_YCValue = true;
	}
	if(msg.port() == in_port_WagesC) {
		WagesC = x;
		isSet_WagesC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PiCGtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PiCGtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_YCValue & isSet_WagesC ) {
	    Tuple<Real> out_value { (YCValue-WagesC) };
		sendOutput(msg.time(), out_port_PiCG, out_value);
	}
	
	return *this ;
}