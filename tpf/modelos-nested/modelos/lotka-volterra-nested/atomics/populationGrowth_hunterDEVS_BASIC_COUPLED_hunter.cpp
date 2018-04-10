#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "populationGrowth_hunterDEVS_BASIC_COUPLED_hunter.h"

using namespace std;

populationGrowth_hunterDEVS_BASIC_COUPLED_hunter::populationGrowth_hunterDEVS_BASIC_COUPLED_hunter(const string &name) :
	Atomic(name),
    in_port_PULSE_V_paramPulse_FP_1_I_1(addInputPort("in_port_PULSE_V_paramPulse_FP_1_I_1")),
    in_port_hunter(addInputPort("in_port_hunter")),
    isSet_PULSE_V_paramPulse_FP_1_I_1(false),
    isSet_hunter(false),
	out_port_populationGrowth_hunter(addOutputPort("out_port_populationGrowth_hunter"))
{
}


Model &populationGrowth_hunterDEVS_BASIC_COUPLED_hunter::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &populationGrowth_hunterDEVS_BASIC_COUPLED_hunter::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_PULSE_V_paramPulse_FP_1_I_1) {
		PULSE_V_paramPulse_FP_1_I_1 = x;
		isSet_PULSE_V_paramPulse_FP_1_I_1 = true;
	}
	if(msg.port() == in_port_hunter) {
		hunter = x;
		isSet_hunter = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &populationGrowth_hunterDEVS_BASIC_COUPLED_hunter::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &populationGrowth_hunterDEVS_BASIC_COUPLED_hunter::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_PULSE_V_paramPulse_FP_1_I_1 & isSet_hunter ) {
	    Tuple<Real> out_value { 0 * hunter + PULSE_V_paramPulse_FP_1_I_1 };
		sendOutput(msg.time(), out_port_populationGrowth_hunter, out_value);
	}
	
	return *this ;
}