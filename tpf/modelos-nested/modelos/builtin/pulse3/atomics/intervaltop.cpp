#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "intervaltop.h"

using namespace std;

intervaltop::intervaltop(const string &name) :
   	in_port_interval(addInputPort("in_port_interval")),
    out_port_interval(addOutputPort("out_port_interval")),
    interval(-1),
    Atomic(name)
{
}


Model &intervaltop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &intervaltop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_interval) {
    	interval = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &intervaltop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &intervaltop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { interval };
	sendOutput(msg.time(),  out_port_interval, out_value);
    return *this ;
}