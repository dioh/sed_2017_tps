#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "specialParamCPredatorModel.h"

using namespace std;

specialParamCPredatorModel::specialParamCPredatorModel(const string &name) :
    specialParamC(addInputPort("specialParamC")),
    specialParamCPredatorModel(addOutputPort("specialParamCPredatorModel")),
    specialParamC(-1),
    Atomic(name)
{
}


Model &specialParamCPredatorModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &specialParamCPredatorModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == specialParamC) {
    	specialParamC = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &specialParamCPredatorModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &specialParamCPredatorModel::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { specialParamC };
	sendOutput(msg.time(),  specialParamCPredatorModel, out_value);
    return *this ;
}