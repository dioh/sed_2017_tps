#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramAtop.h"

using namespace std;

paramAtop::paramAtop(const string &name) :
   	in_port_paramA(addInputPort("in_port_paramA")),
    out_port_paramA(addOutputPort("out_port_paramA")),
    paramA(-1),
    Atomic(name)
{
}


Model &paramAtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramAtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_paramA) {
    	paramA = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramAtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramAtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramA };
	sendOutput(msg.time(),  out_port_paramA, out_value);
    return *this ;
}