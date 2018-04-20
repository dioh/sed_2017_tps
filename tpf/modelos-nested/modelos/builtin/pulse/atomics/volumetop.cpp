#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "volumetop.h"

using namespace std;

volumetop::volumetop(const string &name) :
   	in_port_volume(addInputPort("in_port_volume")),
    out_port_volume(addOutputPort("out_port_volume")),
    volume(-1),
    Atomic(name)
{
}


Model &volumetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &volumetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_volume) {
    	volume = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &volumetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &volumetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { volume };
	sendOutput(msg.time(),  out_port_volume, out_value);
    return *this ;
}