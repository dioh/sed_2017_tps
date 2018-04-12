#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "tauBCtop.h"

using namespace std;

tauBCtop::tauBCtop(const string &name) :
   	in_port_tauBC(addInputPort("in_port_tauBC")),
    out_port_tauBC(addOutputPort("out_port_tauBC")),
    tauBC(-1),
    Atomic(name)
{
}


Model &tauBCtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &tauBCtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_tauBC) {
    	tauBC = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &tauBCtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &tauBCtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { tauBC };
	sendOutput(msg.time(),  out_port_tauBC, out_value);
    return *this ;
}