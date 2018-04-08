#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramBtop.h"

using namespace std;

paramBtop::paramBtop(const string &name) :
    paramB(addInputPort("paramB")),
    paramBtop(addOutputPort("paramBtop")),
    paramB(-1),
    Atomic(name)
{
}


Model &paramBtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramBtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == paramB) {
    	paramB = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramBtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramBtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramB };
	sendOutput(msg.time(),  paramBtop, out_value);
    return *this ;
}