#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "exratop.h"

using namespace std;

exratop::exratop(const string &name) :
   	in_port_exra(addInputPort("in_port_exra")),
    out_port_exra(addOutputPort("out_port_exra")),
    exra(-1),
    Atomic(name)
{
}


Model &exratop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &exratop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_exra) {
    	exra = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &exratop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &exratop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { exra };
	sendOutput(msg.time(),  out_port_exra, out_value);
    return *this ;
}