#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PlusPrey_PreyDEVS_BASIC_COUPLED_Prey.h"

using namespace std;

PlusPrey_PreyDEVS_BASIC_COUPLED_Prey::PlusPrey_PreyDEVS_BASIC_COUPLED_Prey(const string &name) :
	Atomic(name),
    Prey(addInputPort("Prey")),
    paramA(addInputPort("paramA")),
    PreySubModelStock(addInputPort("PreySubModelStock")),
    isSet_Prey(false),
    isSet_paramA(false),
    isSet_PreySubModelStock(false),
	PlusPrey_PreyDEVS_BASIC_COUPLED_Prey(addOutputPort("PlusPrey_PreyDEVS_BASIC_COUPLED_Prey"))
{
}


Model &PlusPrey_PreyDEVS_BASIC_COUPLED_Prey::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PlusPrey_PreyDEVS_BASIC_COUPLED_Prey::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Prey) {
		Prey = x;
		isSet_Prey = true;
	}
	if(msg.port() == paramA) {
		paramA = x;
		isSet_paramA = true;
	}
	if(msg.port() == PreySubModelStock) {
		PreySubModelStock = x;
		isSet_PreySubModelStock = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PlusPrey_PreyDEVS_BASIC_COUPLED_Prey::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PlusPrey_PreyDEVS_BASIC_COUPLED_Prey::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Prey & isSet_paramA & isSet_PreySubModelStock ) {
	    Tuple<Real> out_value { paramA * Prey + PreySubModelStock };
		sendOutput(msg.time(), PlusPrey_PreyDEVS_BASIC_COUPLED_Prey, out_value);
	}
	
	return *this ;
}