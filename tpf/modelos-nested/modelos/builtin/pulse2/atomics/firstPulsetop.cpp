#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "firstPulsetop.h"

using namespace std;

firstPulsetop::firstPulsetop(const string &name) :
   	in_port_firstPulse(addInputPort("in_port_firstPulse")),
    out_port_firstPulse(addOutputPort("out_port_firstPulse")),
    firstPulse(-1),
    Atomic(name)
{
}


Model &firstPulsetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &firstPulsetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_firstPulse) {
    	firstPulse = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &firstPulsetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &firstPulsetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { firstPulse };
	sendOutput(msg.time(),  out_port_firstPulse, out_value);
    return *this ;
}