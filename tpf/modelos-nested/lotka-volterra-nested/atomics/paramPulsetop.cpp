#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramPulsetop.h"

using namespace std;

paramPulsetop::paramPulsetop(const string &name) :
   	in_port_paramPulse(addInputPort("in_port_paramPulse")),
    out_port_paramPulse(addOutputPort("out_port_paramPulse")),
    paramPulse(-1),
    Atomic(name)
{
}


Model &paramPulsetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramPulsetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_paramPulse) {
    	paramPulse = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramPulsetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramPulsetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramPulse };
	sendOutput(msg.time(),  out_port_paramPulse, out_value);
    return *this ;
}