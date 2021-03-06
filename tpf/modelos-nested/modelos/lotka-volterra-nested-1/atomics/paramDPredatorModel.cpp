#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramDPredatorModel.h"

using namespace std;

paramDPredatorModel::paramDPredatorModel(const string &name) :
   	in_port_paramD(addInputPort("in_port_paramD")),
    out_port_paramD(addOutputPort("out_port_paramD")),
    paramD(-1),
    Atomic(name)
{
}


Model &paramDPredatorModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramDPredatorModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_paramD) {
    	paramD = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramDPredatorModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramDPredatorModel::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramD };
	sendOutput(msg.time(),  out_port_paramD, out_value);
    return *this ;
}