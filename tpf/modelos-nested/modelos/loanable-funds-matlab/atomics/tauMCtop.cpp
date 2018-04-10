#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "tauMCtop.h"

using namespace std;

tauMCtop::tauMCtop(const string &name) :
   	in_port_tauMC(addInputPort("in_port_tauMC")),
    out_port_tauMC(addOutputPort("out_port_tauMC")),
    tauMC(-1),
    Atomic(name)
{
}


Model &tauMCtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &tauMCtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_tauMC) {
    	tauMC = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &tauMCtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &tauMCtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { tauMC };
	sendOutput(msg.time(),  out_port_tauMC, out_value);
    return *this ;
}