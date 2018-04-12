#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgPopulation_PopulationDEVS_BASIC_COUPLED_Population.h"

using namespace std;

chgPopulation_PopulationDEVS_BASIC_COUPLED_Population::chgPopulation_PopulationDEVS_BASIC_COUPLED_Population(const string &name) :
	Atomic(name),
    in_port_Betaa(addInputPort("in_port_Betaa")),
    in_port_Population(addInputPort("in_port_Population")),
    isSet_Betaa(false),
    isSet_Population(false),
	out_port_chgPopulation_Population(addOutputPort("out_port_chgPopulation_Population"))
{
}


Model &chgPopulation_PopulationDEVS_BASIC_COUPLED_Population::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgPopulation_PopulationDEVS_BASIC_COUPLED_Population::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Betaa) {
		Betaa = x;
		isSet_Betaa = true;
	}
	if(msg.port() == in_port_Population) {
		Population = x;
		isSet_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgPopulation_PopulationDEVS_BASIC_COUPLED_Population::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgPopulation_PopulationDEVS_BASIC_COUPLED_Population::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Betaa & isSet_Population ) {
	    Tuple<Real> out_value { (Population*Betaa) };
		sendOutput(msg.time(), out_port_chgPopulation_Population, out_value);
	}
	
	return *this ;
}