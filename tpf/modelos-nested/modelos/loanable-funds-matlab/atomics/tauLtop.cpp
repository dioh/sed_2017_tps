#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "tauLtop.h"

using namespace std;

tauLtop::tauLtop(const string &name) :
   	in_port_tauL(addInputPort("in_port_tauL")),
    out_port_tauL(addOutputPort("out_port_tauL")),
    tauL(-1),
    Atomic(name)
{
}


Model &tauLtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &tauLtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_tauL) {
    	tauL = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &tauLtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &tauLtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { tauL };
	sendOutput(msg.time(),  out_port_tauL, out_value);
    return *this ;
}