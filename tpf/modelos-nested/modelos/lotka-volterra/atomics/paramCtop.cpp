#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramCtop.h"

using namespace std;

paramCtop::paramCtop(const string &name) :
   	in_port_paramC(addInputPort("in_port_paramC")),
    out_port_paramC(addOutputPort("out_port_paramC")),
    paramC(-1),
    Atomic(name)
{
}


Model &paramCtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramCtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_paramC) {
    	paramC = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramCtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramCtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramC };
	sendOutput(msg.time(),  out_port_paramC, out_value);
    return *this ;
}