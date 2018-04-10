#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rLValuetop.h"

using namespace std;

rLValuetop::rLValuetop(const string &name) :
   	in_port_rLValue(addInputPort("in_port_rLValue")),
    out_port_rLValue(addOutputPort("out_port_rLValue")),
    rLValue(-1),
    Atomic(name)
{
}


Model &rLValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rLValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_rLValue) {
    	rLValue = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rLValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rLValuetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { rLValue };
	sendOutput(msg.time(),  out_port_rLValue, out_value);
    return *this ;
}