#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator.h"

using namespace std;

PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator::PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator(const string &name) :
	Atomic(name),
    Predator(addInputPort("Predator")),
    Prey(addInputPort("Prey")),
    paramD(addInputPort("paramD")),
    cteVariable(addInputPort("cteVariable")),
    isSet_Predator(false),
    isSet_Prey(false),
    isSet_paramD(false),
    isSet_cteVariable(false),
	PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator(addOutputPort("PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator"))
{
}


Model &PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Predator) {
		Predator = x;
		isSet_Predator = true;
	}
	if(msg.port() == Prey) {
		Prey = x;
		isSet_Prey = true;
	}
	if(msg.port() == paramD) {
		paramD = x;
		isSet_paramD = true;
	}
	if(msg.port() == cteVariable) {
		cteVariable = x;
		isSet_cteVariable = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Predator & isSet_Prey & isSet_paramD & isSet_cteVariable ) {
	    Tuple<Real> out_value { paramD * Predator * Prey + cteVariable };
		sendOutput(msg.time(), PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator, out_value);
	}
	
	return *this ;
}