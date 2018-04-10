#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "velocityOfMoneytop.h"

using namespace std;

velocityOfMoneytop::velocityOfMoneytop(const string &name) :
	Atomic(name),
    in_port_Money(addInputPort("in_port_Money")),
    in_port_Output(addInputPort("in_port_Output")),
    isSet_Money(false),
    isSet_Output(false),
	out_port_velocityOfMoney(addOutputPort("out_port_velocityOfMoney"))
{
}


Model &velocityOfMoneytop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &velocityOfMoneytop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Money) {
		Money = x;
		isSet_Money = true;
	}
	if(msg.port() == in_port_Output) {
		Output = x;
		isSet_Output = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &velocityOfMoneytop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &velocityOfMoneytop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Money & isSet_Output ) {
	    Tuple<Real> out_value { (Output/Money) };
		sendOutput(msg.time(), out_port_velocityOfMoney, out_value);
	}
	
	return *this ;
}