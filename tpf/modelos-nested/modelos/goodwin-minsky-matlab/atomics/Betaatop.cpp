#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Betaatop.h"

using namespace std;

Betaatop::Betaatop(const string &name) :
   	in_port_Betaa(addInputPort("in_port_Betaa")),
    out_port_Betaa(addOutputPort("out_port_Betaa")),
    Betaa(-1),
    Atomic(name)
{
}


Model &Betaatop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Betaatop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_Betaa) {
    	Betaa = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Betaatop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Betaatop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { Betaa };
	sendOutput(msg.time(),  out_port_Betaa, out_value);
    return *this ;
}