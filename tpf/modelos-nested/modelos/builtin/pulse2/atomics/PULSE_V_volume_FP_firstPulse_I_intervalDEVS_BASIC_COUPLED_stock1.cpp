#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1.h"

using namespace std;


PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1::PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1(const string &name) :
	Atomic(name),
	start(addInputPort("start")),
	stop(addInputPort("stop")), 
	out(addOutputPort("out")),
	frequency_time(0,0,10,0),
	on(true),
	dist(0,100),
	rng(random_device()()),
	out_port_PULSE_V_volume_FP_firstPulse_I_interval(addOutputPort("out_port_PULSE_V_volume_FP_firstPulse_I_interval"))
{
}


Model &PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1::initFunction()
{
	holdIn(AtomicState::active, this->frequency_time);
	return *this;
}


Model &PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1::externalFunction(const ExternalMessage &msg)
{
	if(msg.port() == start)
	{
		this->on = true;
		holdIn(AtomicState::active, this->frequency_time);
	}
	else if(msg.port() == stop)
	{
		this->on = false;
		passivate();
	}

	return *this;
}


Model &PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1::internalFunction(const InternalMessage &)
{
	if(this->on)
		holdIn(AtomicState::active, this->frequency_time);
	else
		passivate();

	return *this ;
}


Model &PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1::outputFunction(const CollectMessage &msg)
{
	auto random_int = -50;//this->dist(this->rng);
	Tuple<Real> out_value{Real(random_int)};
	sendOutput(msg.time(), out_port_PULSE_V_volume_FP_firstPulse_I_interval, out_value);
	return *this ;
}