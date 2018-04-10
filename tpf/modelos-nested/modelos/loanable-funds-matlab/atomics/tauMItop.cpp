#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "tauMItop.h"

using namespace std;

tauMItop::tauMItop(const string &name) :
   	in_port_tauMI(addInputPort("in_port_tauMI")),
    out_port_tauMI(addOutputPort("out_port_tauMI")),
    tauMI(-1),
    Atomic(name)
{
}


Model &tauMItop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &tauMItop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_tauMI) {
    	tauMI = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &tauMItop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &tauMItop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { tauMI };
	sendOutput(msg.time(),  out_port_tauMI, out_value);
    return *this ;
}