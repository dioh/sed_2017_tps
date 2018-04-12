#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "tauRtop.h"

using namespace std;

tauRtop::tauRtop(const string &name) :
   	in_port_tauR(addInputPort("in_port_tauR")),
    out_port_tauR(addOutputPort("out_port_tauR")),
    tauR(-1),
    Atomic(name)
{
}


Model &tauRtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &tauRtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_tauR) {
    	tauR = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &tauRtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &tauRtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { tauR };
	sendOutput(msg.time(),  out_port_tauR, out_value);
    return *this ;
}