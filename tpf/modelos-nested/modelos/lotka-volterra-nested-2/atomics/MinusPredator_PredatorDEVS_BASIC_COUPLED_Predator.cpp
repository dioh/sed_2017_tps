#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator.h"

using namespace std;

MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator::MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator(const string &name) :
	Atomic(name),
    in_port_hunter(addInputPort("in_port_hunter")),
    in_port_Predator(addInputPort("in_port_Predator")),
    in_port_specialParamC(addInputPort("in_port_specialParamC")),
    isSet_hunter(false),
    isSet_Predator(false),
    isSet_specialParamC(false),
	out_port_MinusPredator_Predator(addOutputPort("out_port_MinusPredator_Predator"))
{
}


Model &MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_hunter) {
		hunter = x;
		isSet_hunter = true;
	}
	if(msg.port() == in_port_Predator) {
		Predator = x;
		isSet_Predator = true;
	}
	if(msg.port() == in_port_specialParamC) {
		specialParamC = x;
		isSet_specialParamC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_hunter & isSet_Predator & isSet_specialParamC ) {
	    Tuple<Real> out_value { specialParamC * Predator + 0 * hunter };
		sendOutput(msg.time(), out_port_MinusPredator_Predator, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_MinusPredator_Predator, out_value);
	}
	
	return *this ;
}