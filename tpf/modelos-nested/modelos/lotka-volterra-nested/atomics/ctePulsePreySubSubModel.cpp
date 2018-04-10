#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ctePulsePreySubSubModel.h"

using namespace std;

ctePulsePreySubSubModel::ctePulsePreySubSubModel(const string &name) :
   	in_port_ctePulse(addInputPort("in_port_ctePulse")),
    out_port_ctePulse(addOutputPort("out_port_ctePulse")),
    ctePulse(-1),
    Atomic(name)
{
}


Model &ctePulsePreySubSubModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ctePulsePreySubSubModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_ctePulse) {
    	ctePulse = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ctePulsePreySubSubModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ctePulsePreySubSubModel::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { ctePulse };
	sendOutput(msg.time(),  out_port_ctePulse, out_value);
    return *this ;
}