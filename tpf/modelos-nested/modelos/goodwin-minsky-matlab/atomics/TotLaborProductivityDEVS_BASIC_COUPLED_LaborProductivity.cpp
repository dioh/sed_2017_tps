#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity.h"

using namespace std;

TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(const string &name) :
	Atomic(name),
	in_plus_port_chgLaborProductivity_LaborProductivity(addInputPort("in_plus_port_chgLaborProductivity_LaborProductivity")),
	isSet_chgLaborProductivity_LaborProductivity(false),
	out_port_TotLaborProductivity(addOutputPort("out_port_TotLaborProductivity"))
	{
}


Model &TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgLaborProductivity_LaborProductivity) {
		chgLaborProductivity_LaborProductivity = x;
		isSet_chgLaborProductivity_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_chgLaborProductivity_LaborProductivity) { plus = plus + chgLaborProductivity_LaborProductivity; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotLaborProductivity, out_value);
	return *this ;
}