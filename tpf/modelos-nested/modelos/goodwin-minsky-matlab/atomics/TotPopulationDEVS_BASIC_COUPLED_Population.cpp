#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotPopulationDEVS_BASIC_COUPLED_Population.h"

using namespace std;

TotPopulationDEVS_BASIC_COUPLED_Population::TotPopulationDEVS_BASIC_COUPLED_Population(const string &name) :
	Atomic(name),
	in_plus_port_chgPopulation_Population(addInputPort("in_plus_port_chgPopulation_Population")),
	isSet_chgPopulation_Population(false),
	out_port_TotPopulation(addOutputPort("out_port_TotPopulation"))
	{
}


Model &TotPopulationDEVS_BASIC_COUPLED_Population::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotPopulationDEVS_BASIC_COUPLED_Population::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgPopulation_Population) {
		chgPopulation_Population = x;
		isSet_chgPopulation_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotPopulationDEVS_BASIC_COUPLED_Population::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotPopulationDEVS_BASIC_COUPLED_Population::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_chgPopulation_Population) { plus = plus + chgPopulation_Population; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotPopulation, out_value);
	return *this ;
}