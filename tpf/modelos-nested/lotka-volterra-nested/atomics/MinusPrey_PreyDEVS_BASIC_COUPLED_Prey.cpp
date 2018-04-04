#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "MinusPrey_PreyDEVS_BASIC_COUPLED_Prey.h"

using namespace std;

MinusPrey_PreyDEVS_BASIC_COUPLED_Prey::MinusPrey_PreyDEVS_BASIC_COUPLED_Prey(const string &name) :
	Atomic(name),
    Predator(addInputPort("Predator")),
    Prey(addInputPort("Prey")),
    paramB(addInputPort("paramB")),
    PreySubSubModelStock(addInputPort("PreySubSubModelStock")),
    isSet_Predator(false),
    isSet_Prey(false),
    isSet_paramB(false),
    isSet_PreySubSubModelStock(false),
	MinusPrey_PreyDEVS_BASIC_COUPLED_Prey(addOutputPort("MinusPrey_PreyDEVS_BASIC_COUPLED_Prey"))
{
}


Model &MinusPrey_PreyDEVS_BASIC_COUPLED_Prey::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &MinusPrey_PreyDEVS_BASIC_COUPLED_Prey::externalFunction(const ExternalMessage &msg)
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
	if(msg.port() == paramB) {
		paramB = x;
		isSet_paramB = true;
	}
	if(msg.port() == PreySubSubModelStock) {
		PreySubSubModelStock = x;
		isSet_PreySubSubModelStock = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &MinusPrey_PreyDEVS_BASIC_COUPLED_Prey::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &MinusPrey_PreyDEVS_BASIC_COUPLED_Prey::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Predator & isSet_Prey & isSet_paramB & isSet_PreySubSubModelStock ) {
	    Tuple<Real> out_value { Prey * paramB * Predator + 0 * PreySubSubModelStock };
		sendOutput(msg.time(), MinusPrey_PreyDEVS_BASIC_COUPLED_Prey, out_value);
	}
	
	return *this ;
}