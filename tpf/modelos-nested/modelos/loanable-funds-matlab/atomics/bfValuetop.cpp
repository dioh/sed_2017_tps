#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "bfValuetop.h"

using namespace std;

bfValuetop::bfValuetop(const string &name) :
   	in_port_bfValue(addInputPort("in_port_bfValue")),
    out_port_bfValue(addOutputPort("out_port_bfValue")),
    bfValue(-1),
    Atomic(name)
{
}


Model &bfValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &bfValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_bfValue) {
    	bfValue = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &bfValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &bfValuetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { bfValue };
	sendOutput(msg.time(),  out_port_bfValue, out_value);
    return *this ;
}