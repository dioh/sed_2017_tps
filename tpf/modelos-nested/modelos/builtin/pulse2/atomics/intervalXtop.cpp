#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "intervalXtop.h"

using namespace std;

intervalXtop::intervalXtop(const string &name) :
   	in_port_intervalX(addInputPort("in_port_intervalX")),
    out_port_intervalX(addOutputPort("out_port_intervalX")),
    intervalX(-1),
    Atomic(name)
{
}


Model &intervalXtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &intervalXtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_intervalX) {
    	intervalX = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &intervalXtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &intervalXtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { intervalX };
	sendOutput(msg.time(),  out_port_intervalX, out_value);
    return *this ;
}