#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "piStop.h"

using namespace std;

piStop::piStop(const string &name) :
   	in_port_piS(addInputPort("in_port_piS")),
    out_port_piS(addOutputPort("out_port_piS")),
    piS(-1),
    Atomic(name)
{
}


Model &piStop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &piStop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_piS) {
    	piS = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &piStop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &piStop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { piS };
	sendOutput(msg.time(),  out_port_piS, out_value);
    return *this ;
}