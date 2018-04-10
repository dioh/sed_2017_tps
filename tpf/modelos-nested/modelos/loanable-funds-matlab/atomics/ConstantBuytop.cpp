#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConstantBuytop.h"

using namespace std;

ConstantBuytop::ConstantBuytop(const string &name) :
	Atomic(name),
    in_port_PiCG(addInputPort("in_port_PiCG")),
    in_port_CPIValue(addInputPort("in_port_CPIValue")),
    isSet_PiCG(false),
    isSet_CPIValue(false),
	out_port_ConstantBuy(addOutputPort("out_port_ConstantBuy"))
{
}


Model &ConstantBuytop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConstantBuytop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_PiCG) {
		PiCG = x;
		isSet_PiCG = true;
	}
	if(msg.port() == in_port_CPIValue) {
		CPIValue = x;
		isSet_CPIValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConstantBuytop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConstantBuytop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_PiCG & isSet_CPIValue ) {
	    Tuple<Real> out_value { (PiCG*CPIValue) };
		sendOutput(msg.time(), out_port_ConstantBuy, out_value);
	}
	
	return *this ;
}