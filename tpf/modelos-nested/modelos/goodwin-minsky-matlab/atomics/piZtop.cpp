#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "piZtop.h"

using namespace std;

piZtop::piZtop(const string &name) :
   	in_port_piZ(addInputPort("in_port_piZ")),
    out_port_piZ(addOutputPort("out_port_piZ")),
    piZ(-1),
    Atomic(name)
{
}


Model &piZtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &piZtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_piZ) {
    	piZ = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &piZtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &piZtop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { piZ };
	sendOutput(msg.time(),  out_port_piZ, out_value);
    return *this ;
}