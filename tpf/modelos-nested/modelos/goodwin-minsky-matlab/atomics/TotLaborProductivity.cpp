#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotLaborProductivity.h"

using namespace std;

TotLaborProductivity::TotLaborProductivity(const string &name) :
	Atomic(name),
	in_plus_port_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(addInputPort("in_plus_port_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity")),
	isSet_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(false),
	out_port_TotLaborProductivity(addOutputPort("out_port_TotLaborProductivity"))
	{
}


Model &TotLaborProductivity::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotLaborProductivity::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity) {
		chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity = x;
		isSet_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotLaborProductivity::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotLaborProductivity::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity) {
		plus = plus + chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotLaborProductivity, out_value);
		}

	return *this ;
}