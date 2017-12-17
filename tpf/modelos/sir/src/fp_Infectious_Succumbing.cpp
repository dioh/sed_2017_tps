#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_Infectious_Succumbing.h"

using namespace std;

fp_Infectious_Succumbing::fp_Infectious_Succumbing(const string &name) :
	Atomic(name),
	in_Susceptible(addInputPort("in_Susceptible")),
	in_Infectious(addInputPort("in_Infectious")),
	in_TotalPopulation(addInputPort("in_TotalPopulation")),
	in_ContactInfectivity(addInputPort("in_ContactInfectivity")),
	isSet_Susceptible(false),
	isSet_Infectious(false),
	isSet_TotalPopulation(false),
	isSet_ContactInfectivity(false),
	out(addOutputPort("out"))

{
}


Model &fp_Infectious_Succumbing::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_Infectious_Succumbing::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Susceptible) {
		Susceptible = x;
		isSet_Susceptible = true;
	}
	if(msg.port() == in_Infectious) {
		Infectious = x;
		isSet_Infectious = true;
	}
	if(msg.port() == in_TotalPopulation) {
		TotalPopulation = x;
		isSet_TotalPopulation = true;
	}
	if(msg.port() == in_ContactInfectivity) {
		ContactInfectivity = x;
		isSet_ContactInfectivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_Infectious_Succumbing::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_Infectious_Succumbing::outputFunction(const CollectMessage &msg)
{
	if( isSet_Susceptible & isSet_Infectious & isSet_TotalPopulation & isSet_ContactInfectivity ) {
		double val = Susceptible*Infectious/TotalPopulation*ContactInfectivity;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}