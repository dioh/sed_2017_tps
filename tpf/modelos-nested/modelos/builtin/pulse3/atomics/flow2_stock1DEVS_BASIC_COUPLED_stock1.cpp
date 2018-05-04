#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "flow2_stock1DEVS_BASIC_COUPLED_stock1.h"

using namespace std;

flow2_stock1DEVS_BASIC_COUPLED_stock1::flow2_stock1DEVS_BASIC_COUPLED_stock1(const string &name) :
	Atomic(name),
    in_port_stock1(addInputPort("in_port_stock1")),
    in_port_PULSE_V_volume_FP_firstPulse_I_interval_flow2(addInputPort("in_port_PULSE_V_volume_FP_firstPulse_I_interval_flow2")),
    isSet_stock1(false),
    isSet_PULSE_V_volume_FP_firstPulse_I_interval_flow2(false),
	out_port_flow2_stock1(addOutputPort("out_port_flow2_stock1"))
{
}


Model &flow2_stock1DEVS_BASIC_COUPLED_stock1::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &flow2_stock1DEVS_BASIC_COUPLED_stock1::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_stock1) {
		stock1 = x;
		isSet_stock1 = true;
	}
	if(msg.port() == in_port_PULSE_V_volume_FP_firstPulse_I_interval_flow2) {
		PULSE_V_volume_FP_firstPulse_I_interval_flow2 = x;
		isSet_PULSE_V_volume_FP_firstPulse_I_interval_flow2 = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &flow2_stock1DEVS_BASIC_COUPLED_stock1::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &flow2_stock1DEVS_BASIC_COUPLED_stock1::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_stock1 & isSet_PULSE_V_volume_FP_firstPulse_I_interval_flow2 ) {
	    Tuple<Real> out_value { PULSE_V_volume_FP_firstPulse_I_interval_flow2 / stock1 };
		sendOutput(msg.time(), out_port_flow2_stock1, out_value);
	}
	
	return *this ;
}