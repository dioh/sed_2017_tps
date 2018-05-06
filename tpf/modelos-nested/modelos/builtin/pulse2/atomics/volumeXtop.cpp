#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "volumeXtop.h"

using namespace std;

volumeXtop::volumeXtop(const string &name) :
   	in_port_volumeX(addInputPort("in_port_volumeX")),
    out_port_volumeX(addOutputPort("out_port_volumeX")),
    volumeX(-1),
    Atomic(name)
{
}


Model &volumeXtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &volumeXtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_volumeX) {
    	volumeX = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &volumeXtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &volumeXtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { volumeX };
	sendOutput(msg.time(),  out_port_volumeX, out_value);
    return *this ;
}