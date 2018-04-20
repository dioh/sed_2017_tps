#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "SuccumbingPlus.h"

using namespace std;

SuccumbingPlus::SuccumbingPlus(const string &name) :
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


Model &SuccumbingPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &SuccumbingPlus::externalFunction(const ExternalMessage &msg)
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


Model &SuccumbingPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &SuccumbingPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Susceptibles & isSet_val_Infected & isSet_val_InfectionRate & isSet_val_TotalPopulation ) {
		double val = (val_Susceptibles * val_Infected) / (val_InfectionRate * val_TotalPopulation);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}