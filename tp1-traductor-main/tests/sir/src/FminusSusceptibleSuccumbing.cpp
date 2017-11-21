#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusSusceptibleSuccumbing.h"

using namespace std;

FminusSusceptibleSuccumbing::FminusSusceptibleSuccumbing(const string &name) :
	Atomic(name),
	in_susceptibleIntegrator(addInputPort("in_susceptibleIntegrator")),
	in_infectiousIntegrator(addInputPort("in_infectiousIntegrator")),
	in_totalPopulation(addInputPort("in_totalPopulation")),
	in_contactInfectivity(addInputPort("in_contactInfectivity")),
	isSet_susceptibleIntegrator(false),
	isSet_infectiousIntegrator(false),
	isSet_totalPopulation(false),
	isSet_contactInfectivity(false),
	out(addOutputPort("out"))
{
}


Model &FminusSusceptibleSuccumbing::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusSusceptibleSuccumbing::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_susceptibleIntegrator) {
		susceptibleIntegrator = x;
		isSet_susceptibleIntegrator = true;
	}
	if(msg.port() == in_infectiousIntegrator) {
		infectiousIntegrator = x;
		isSet_infectiousIntegrator = true;
	}
	if(msg.port() == in_totalPopulation) {
		totalPopulation = x;
		isSet_totalPopulation = true;
	}
	if(msg.port() == in_contactInfectivity) {
		contactInfectivity = x;
		isSet_contactInfectivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusSusceptibleSuccumbing::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusSusceptibleSuccumbing::outputFunction(const CollectMessage &msg)
{
	if( isSet_susceptibleIntegrator & isSet_infectiousIntegrator & isSet_totalPopulation & isSet_contactInfectivity ) {
		double val = susceptibleIntegrator*infectiousIntegrator/totalPopulation*contactInfectivity;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}