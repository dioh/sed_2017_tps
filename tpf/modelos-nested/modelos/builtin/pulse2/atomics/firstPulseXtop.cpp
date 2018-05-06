#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "firstPulseXtop.h"

using namespace std;

firstPulseXtop::firstPulseXtop(const string &name) :
   	in_port_firstPulseX(addInputPort("in_port_firstPulseX")),
    out_port_firstPulseX(addOutputPort("out_port_firstPulseX")),
    firstPulseX(-1),
    Atomic(name)
{
}


Model &firstPulseXtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &firstPulseXtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_firstPulseX) {
    	firstPulseX = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &firstPulseXtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &firstPulseXtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { firstPulseX };
	sendOutput(msg.time(),  out_port_firstPulseX, out_value);
    return *this ;
}