#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "cteVariablePredatorModel.h"

using namespace std;

cteVariablePredatorModel::cteVariablePredatorModel(const string &name) :
    cteVariable(addInputPort("cteVariable")),
    cteVariablePredatorModel(addOutputPort("cteVariablePredatorModel")),
    cteVariable(-1),
    Atomic(name)
{
}


Model &cteVariablePredatorModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &cteVariablePredatorModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == cteVariable) {
    	cteVariable = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &cteVariablePredatorModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &cteVariablePredatorModel::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { cteVariable };
	sendOutput(msg.time(),  cteVariablePredatorModel, out_value);
    return *this ;
}