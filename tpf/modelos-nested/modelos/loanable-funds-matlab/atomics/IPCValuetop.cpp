#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "IPCValuetop.h"

using namespace std;

IPCValuetop::IPCValuetop(const string &name) :
   	in_port_IPCValue(addInputPort("in_port_IPCValue")),
    out_port_IPCValue(addOutputPort("out_port_IPCValue")),
    IPCValue(-1),
    Atomic(name)
{
}


Model &IPCValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &IPCValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_IPCValue) {
    	IPCValue = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &IPCValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &IPCValuetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { IPCValue };
	sendOutput(msg.time(),  out_port_IPCValue, out_value);
    return *this ;
}