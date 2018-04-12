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
    in_port_paramC(addInputPort("in_port_paramC")),
    in_port_Predator(addInputPort("in_port_Predator")),
    isSet_paramC(false),
    isSet_Predator(false),
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

	if(msg.port() == in_port_paramC) {
		paramC = x;
		isSet_paramC = true;
	}
	if(msg.port() == in_port_Predator) {
		Predator = x;
		isSet_Predator = true;
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
	
	if( isSet_paramC & isSet_Predator ) {
	    Tuple<Real> out_value { paramC * Predator };
		sendOutput(msg.time(), out_port_MinusPredator_Predator, out_value);
	}
	
	return *this ;
}