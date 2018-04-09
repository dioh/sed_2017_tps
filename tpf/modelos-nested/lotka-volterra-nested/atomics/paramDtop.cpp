#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramDtop.h"

using namespace std;

paramDtop::paramDtop(const string &name) :
    paramD(addInputPort("paramD")),
    paramDtop(addOutputPort("paramDtop")),
    paramD(-1),
    Atomic(name)
{
}


Model &paramDtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramDtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == paramD) {
    	paramD = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramDtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramDtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramD };
	sendOutput(msg.time(),  paramDtop, out_value);
    return *this ;
}