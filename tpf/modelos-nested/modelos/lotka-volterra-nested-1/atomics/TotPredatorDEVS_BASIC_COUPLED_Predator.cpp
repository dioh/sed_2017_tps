#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotPredatorDEVS_BASIC_COUPLED_Predator.h"

using namespace std;

TotPredatorDEVS_BASIC_COUPLED_Predator::TotPredatorDEVS_BASIC_COUPLED_Predator(const string &name) :
	Atomic(name),
	in_plus_port_PlusPredator_Predator(addInputPort("in_plus_port_PlusPredator_Predator")),
	in_minus_port_MinusPredator_Predator(addInputPort("in_minus_port_MinusPredator_Predator")),
	isSet_PlusPredator_Predator(false),
	isSet_MinusPredator_Predator(false),
	out_port_TotPredator(addOutputPort("out_port_TotPredator"))
	{
}


Model &TotPredatorDEVS_BASIC_COUPLED_Predator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotPredatorDEVS_BASIC_COUPLED_Predator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_PlusPredator_Predator) {
		PlusPredator_Predator = x;
		isSet_PlusPredator_Predator = true;
	}
	if(msg.port() == in_minus_port_MinusPredator_Predator) {
		MinusPredator_Predator = x;
		isSet_MinusPredator_Predator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotPredatorDEVS_BASIC_COUPLED_Predator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotPredatorDEVS_BASIC_COUPLED_Predator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_PlusPredator_Predator & isSet_MinusPredator_Predator) {
		plus = plus + PlusPredator_Predator;
		minus = minus + MinusPredator_Predator;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotPredator, out_value);
		}

	return *this ;
}