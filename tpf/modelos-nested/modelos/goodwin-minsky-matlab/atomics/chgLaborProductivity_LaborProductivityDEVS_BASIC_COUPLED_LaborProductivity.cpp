#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity.h"

using namespace std;

chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(const string &name) :
	Atomic(name),
    in_port_Alphaa(addInputPort("in_port_Alphaa")),
    in_port_LaborProductivity(addInputPort("in_port_LaborProductivity")),
    isSet_Alphaa(false),
    isSet_LaborProductivity(false),
	out_port_chgLaborProductivity_LaborProductivity(addOutputPort("out_port_chgLaborProductivity_LaborProductivity"))
{
}


Model &chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Alphaa) {
		Alphaa = x;
		isSet_Alphaa = true;
	}
	if(msg.port() == in_port_LaborProductivity) {
		LaborProductivity = x;
		isSet_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Alphaa & isSet_LaborProductivity ) {
	    Tuple<Real> out_value { (Alphaa*LaborProductivity) };
		sendOutput(msg.time(), out_port_chgLaborProductivity_LaborProductivity, out_value);
	}
	
	return *this ;
}