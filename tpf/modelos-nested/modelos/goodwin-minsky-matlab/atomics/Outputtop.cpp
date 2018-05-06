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
    in_port_Capital(addInputPort("in_port_Capital")),
    in_port_velocityOfMoney(addInputPort("in_port_velocityOfMoney")),
    isSet_Capital(false),
    isSet_velocityOfMoney(false),
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

	if(msg.port() == in_port_Capital) {
		Capital = x;
		isSet_Capital = true;
	}
	if(msg.port() == in_port_velocityOfMoney) {
		velocityOfMoney = x;
		isSet_velocityOfMoney = true;
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
	
	if( isSet_Capital & isSet_velocityOfMoney ) {
	    Tuple<Real> out_value { (Capital/velocityOfMoney) };
		sendOutput(msg.time(), out_port_Output, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_Output, out_value);
	}
	
	return *this ;
}