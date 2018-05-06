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
    in_port_Predator(addInputPort("in_port_Predator")),
    in_port_Prey(addInputPort("in_port_Prey")),
    in_port_paramB(addInputPort("in_port_paramB")),
    isSet_Predator(false),
    isSet_Prey(false),
    isSet_paramB(false),
	out_port_MinusPrey_Prey(addOutputPort("out_port_MinusPrey_Prey"))
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

	if(msg.port() == in_port_Predator) {
		Predator = x;
		isSet_Predator = true;
	}
	if(msg.port() == in_port_Prey) {
		Prey = x;
		isSet_Prey = true;
	}
	if(msg.port() == in_port_paramB) {
		paramB = x;
		isSet_paramB = true;
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
	
	if( isSet_Predator & isSet_Prey & isSet_paramB ) {
	    Tuple<Real> out_value { Prey * paramB * Predator };
		sendOutput(msg.time(), out_port_MinusPrey_Prey, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_MinusPrey_Prey, out_value);
	}
	
	return *this ;
}