#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "CPIValuetop.h"

using namespace std;

CPIValuetop::CPIValuetop(const string &name) :
   	in_port_CPIValue(addInputPort("in_port_CPIValue")),
    out_port_CPIValue(addOutputPort("out_port_CPIValue")),
    CPIValue(-1),
    Atomic(name)
{
}


Model &CPIValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &CPIValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_CPIValue) {
    	CPIValue = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &CPIValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &CPIValuetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { CPIValue };
	sendOutput(msg.time(),  out_port_CPIValue, out_value);
    return *this ;
}