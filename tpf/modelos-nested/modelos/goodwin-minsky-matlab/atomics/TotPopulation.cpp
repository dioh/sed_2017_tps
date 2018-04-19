#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotPopulation.h"

using namespace std;

TotPopulation::TotPopulation(const string &name) :
	Atomic(name),
	in_plus_port_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population(addInputPort("in_plus_port_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population")),
	isSet_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population(false),
	out_port_TotPopulation(addOutputPort("out_port_TotPopulation"))
	{
}


Model &TotPopulation::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotPopulation::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population) {
		chgPopulation_PopulationDEVS_BASIC_COUPLED_Population = x;
		isSet_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotPopulation::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotPopulation::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population) {
		plus = plus + chgPopulation_PopulationDEVS_BASIC_COUPLED_Population;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotPopulation, out_value);
		}

	return *this ;
}