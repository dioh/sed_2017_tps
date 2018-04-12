#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "tauWCtop.h"

using namespace std;

tauWCtop::tauWCtop(const string &name) :
   	in_port_tauWC(addInputPort("in_port_tauWC")),
    out_port_tauWC(addOutputPort("out_port_tauWC")),
    tauWC(-1),
    Atomic(name)
{
}


Model &tauWCtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &tauWCtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_tauWC) {
    	tauWC = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &tauWCtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &tauWCtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { tauWC };
	sendOutput(msg.time(),  out_port_tauWC, out_value);
    return *this ;
}