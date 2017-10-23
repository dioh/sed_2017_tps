#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusSusceptible.h"

using namespace std;

FminusSusceptible::FminusSusceptible(const string &name) :
	Atomic(name),
	inInfectiousIntegrator(addInputPort("inInfectiousIntegrator")),
	inSusceptibleIntegrator(addInputPort("inSusceptibleIntegrator")),
	inTotalPopulation(addInputPort("inTotalPopulation")),
	inContactInfectivity(addInputPort("inContactInfectivity")),
	isSetInfectiousIntegrator(false),
	isSetSusceptibleIntegrator(false),
	isSetTotalPopulation(false),
	isSetContactInfectivity(false),
	out(addOutputPort("out"))
{
}


Model &FminusSusceptible::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusSusceptible::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inInfectiousIntegrator) {
		infectiousIntegrator = x;
		isSetInfectiousIntegrator = true;
	}
	if(msg.port() == inSusceptibleIntegrator) {
		susceptibleIntegrator = x;
		isSetSusceptibleIntegrator = true;
	}
	if(msg.port() == inTotalPopulation) {
		totalPopulation = x;
		isSetTotalPopulation = true;
	}
	if(msg.port() == inContactInfectivity) {
		contactInfectivity = x;
		isSetContactInfectivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusSusceptible::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusSusceptible::outputFunction(const CollectMessage &msg)
{
	if( isSetInfectiousIntegrator && isSetSusceptibleIntegrator && isSetTotalPopulation && isSetContactInfectivity ) {
		double val = susceptibleIntegrator*infectiousIntegrator/totalPopulation*contactInfectivity;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}