#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPopulationchgPopulation.h"

using namespace std;

FplusPopulationchgPopulation::FplusPopulationchgPopulation(const string &name) :
	Atomic(name),
	in_populationIntegrator(addInputPort("in_populationIntegrator")),
	in_betaChgpopulationIntegrator(addInputPort("in_betaChgpopulationIntegrator")),
	isSet_populationIntegrator(false),
	isSet_betaChgpopulationIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FplusPopulationchgPopulation::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPopulationchgPopulation::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_populationIntegrator) {
		populationIntegrator = x;
		isSet_populationIntegrator = true;
	}
	if(msg.port() == in_betaChgpopulationIntegrator) {
		betaChgpopulationIntegrator = x;
		isSet_betaChgpopulationIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPopulationchgPopulation::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPopulationchgPopulation::outputFunction(const CollectMessage &msg)
{
	if( isSet_populationIntegrator & isSet_betaChgpopulationIntegrator ) {
		double val = populationIntegrator * betaChgpopulationIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}