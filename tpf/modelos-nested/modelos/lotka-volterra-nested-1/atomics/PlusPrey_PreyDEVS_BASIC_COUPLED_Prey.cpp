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
    in_port_Prey(addInputPort("in_port_Prey")),
    in_port_paramA(addInputPort("in_port_paramA")),
    isSet_Prey(false),
    isSet_paramA(false),
	out_port_PlusPrey_Prey(addOutputPort("out_port_PlusPrey_Prey"))
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

	if(msg.port() == in_port_Prey) {
		Prey = x;
		isSet_Prey = true;
	}
	if(msg.port() == in_port_paramA) {
		paramA = x;
		isSet_paramA = true;
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
	
	if( isSet_Prey & isSet_paramA ) {
	    Tuple<Real> out_value { paramA * Prey };
		sendOutput(msg.time(), out_port_PlusPrey_Prey, out_value);
	}
	
	return *this ;
}