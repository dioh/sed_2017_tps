#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramAPreyModel.h"

using namespace std;

paramAPreyModel::paramAPreyModel(const string &name) :
    paramA(addInputPort("paramA")),
    paramAPreyModel(addOutputPort("paramAPreyModel")),
    paramA(-1),
    Atomic(name)
{
}


Model &paramAPreyModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramAPreyModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == paramA) {
    	paramA = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramAPreyModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramAPreyModel::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { paramA };
	sendOutput(msg.time(),  paramAPreyModel, out_value);
    return *this ;
}