#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Alphaatop.h"

using namespace std;

Alphaatop::Alphaatop(const string &name) :
   	in_port_Alphaa(addInputPort("in_port_Alphaa")),
    out_port_Alphaa(addOutputPort("out_port_Alphaa")),
    Alphaa(-1),
    Atomic(name)
{
}


Model &Alphaatop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Alphaatop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_Alphaa) {
    	Alphaa = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Alphaatop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Alphaatop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { Alphaa };
	sendOutput(msg.time(),  out_port_Alphaa, out_value);
    return *this ;
}