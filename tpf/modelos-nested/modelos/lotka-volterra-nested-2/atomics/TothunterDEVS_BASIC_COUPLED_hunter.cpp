#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TothunterDEVS_BASIC_COUPLED_hunter.h"

using namespace std;

TothunterDEVS_BASIC_COUPLED_hunter::TothunterDEVS_BASIC_COUPLED_hunter(const string &name) :
	Atomic(name),
	in_plus_port_populationGrowth_hunter(addInputPort("in_plus_port_populationGrowth_hunter")),
	in_minus_port_populationDeath_hunter(addInputPort("in_minus_port_populationDeath_hunter")),
	isSet_populationGrowth_hunter(false),
	isSet_populationDeath_hunter(false),
	out_port_Tothunter(addOutputPort("out_port_Tothunter"))
	{
}


Model &TothunterDEVS_BASIC_COUPLED_hunter::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TothunterDEVS_BASIC_COUPLED_hunter::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_populationGrowth_hunter) {
		populationGrowth_hunter = x;
		isSet_populationGrowth_hunter = true;
	}
	if(msg.port() == in_minus_port_populationDeath_hunter) {
		populationDeath_hunter = x;
		isSet_populationDeath_hunter = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TothunterDEVS_BASIC_COUPLED_hunter::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TothunterDEVS_BASIC_COUPLED_hunter::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_populationGrowth_hunter) { plus = plus + populationGrowth_hunter; }if(isSet_populationDeath_hunter) { minus = minus + populationDeath_hunter; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_Tothunter, out_value);
	return *this ;
}