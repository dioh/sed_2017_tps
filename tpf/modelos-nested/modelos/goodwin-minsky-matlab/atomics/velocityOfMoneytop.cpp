#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "velocityOfMoneytop.h"

using namespace std;

velocityOfMoneytop::velocityOfMoneytop(const string &name) :
   	in_port_velocityOfMoney(addInputPort("in_port_velocityOfMoney")),
    out_port_velocityOfMoney(addOutputPort("out_port_velocityOfMoney")),
    velocityOfMoney(-1),
    Atomic(name)
{
}


Model &velocityOfMoneytop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &velocityOfMoneytop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_velocityOfMoney) {
    	velocityOfMoney = x;
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
    Tuple<Real> out_value { velocityOfMoney };
	sendOutput(msg.time(),  out_port_velocityOfMoney, out_value);
    return *this ;
}