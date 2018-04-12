#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Outputtop.h"

using namespace std;

Outputtop::Outputtop(const string &name) :
	Atomic(name),
    in_port_YCValue(addInputPort("in_port_YCValue")),
    in_port_YIValue(addInputPort("in_port_YIValue")),
    isSet_YCValue(false),
    isSet_YIValue(false),
	out_port_Output(addOutputPort("out_port_Output"))
{
}


Model &Outputtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Outputtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_YCValue) {
		YCValue = x;
		isSet_YCValue = true;
	}
	if(msg.port() == in_port_YIValue) {
		YIValue = x;
		isSet_YIValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Outputtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Outputtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_YCValue & isSet_YIValue ) {
	    Tuple<Real> out_value { (YCValue+YIValue) };
		sendOutput(msg.time(), out_port_Output, out_value);
	}
	
	return *this ;
}