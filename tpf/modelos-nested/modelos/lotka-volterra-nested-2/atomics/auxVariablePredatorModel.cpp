#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "auxVariablePredatorModel.h"

using namespace std;

auxVariablePredatorModel::auxVariablePredatorModel(const string &name) :
	Atomic(name),
    in_port_cteVariable(addInputPort("in_port_cteVariable")),
    isSet_cteVariable(false),
	out_port_auxVariable(addOutputPort("out_port_auxVariable"))
{
}


Model &auxVariablePredatorModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &auxVariablePredatorModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_cteVariable) {
		cteVariable = x;
		isSet_cteVariable = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &auxVariablePredatorModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &auxVariablePredatorModel::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_cteVariable ) {
	    Tuple<Real> out_value { cteVariable };
		sendOutput(msg.time(), out_port_auxVariable, out_value);
	}
	
	return *this ;
}