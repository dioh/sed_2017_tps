#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "deltaKRealtop.h"

using namespace std;

deltaKRealtop::deltaKRealtop(const string &name) :
   	in_port_deltaKReal(addInputPort("in_port_deltaKReal")),
    out_port_deltaKReal(addOutputPort("out_port_deltaKReal")),
    deltaKReal(-1),
    Atomic(name)
{
}


Model &deltaKRealtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &deltaKRealtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_deltaKReal) {
    	deltaKReal = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &deltaKRealtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &deltaKRealtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { deltaKReal };
	sendOutput(msg.time(),  out_port_deltaKReal, out_value);
    return *this ;
}