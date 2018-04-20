#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "SuccumbingMinus.h"

using namespace std;

SuccumbingMinus::SuccumbingMinus(const string &name) :
	Atomic(name),
	Susceptibles(addInputPort("Susceptibles")),
	Infected(addInputPort("Infected")),
	InfectionRate(addInputPort("InfectionRate")),
	TotalPopulation(addInputPort("TotalPopulation")),
	isSet_val_Susceptibles(false),
	isSet_val_Infected(false),
	isSet_val_InfectionRate(false),
	isSet_val_TotalPopulation(false),
	out(addOutputPort("out"))
{
}


Model &SuccumbingMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &SuccumbingMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Susceptibles) {
		val_Susceptibles = x;
		isSet_val_Susceptibles = true;
	}
	if(msg.port() == Infected) {
		val_Infected = x;
		isSet_val_Infected = true;
	}
	if(msg.port() == InfectionRate) {
		val_InfectionRate = x;
		isSet_val_InfectionRate = true;
	}
	if(msg.port() == TotalPopulation) {
		val_TotalPopulation = x;
		isSet_val_TotalPopulation = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &SuccumbingMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &SuccumbingMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Susceptibles & isSet_val_Infected & isSet_val_InfectionRate & isSet_val_TotalPopulation ) {
		double val = (val_Susceptibles * val_Infected) / (val_InfectionRate * val_TotalPopulation);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}