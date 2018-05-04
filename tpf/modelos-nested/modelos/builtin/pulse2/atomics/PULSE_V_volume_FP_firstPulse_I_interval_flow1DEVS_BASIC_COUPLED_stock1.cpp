#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1.h"

using namespace std;


PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1::PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1(const string &name) :
	Atomic(name),
	start(addInputPort("start")),
	stop(addInputPort("stop")), 
	out(addOutputPort("out")),
	//frequency_time(0,0,10,0),
	on(true),
	dist(0,100),
	rng(random_device()()),
	out_port_PULSE_V_volume_FP_firstPulse_I_interval_flow1(addOutputPort("out_port_PULSE_V_volume_FP_firstPulse_I_interval_flow1")),
	in_port_volume(addInputPort("in_port_volume"))
{
}


Model &PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1::initFunction()
{
	//holdIn(AtomicState::active, this->frequency_time);
	// TODO : get frequency_time parameters from get_params in .ma file
	this->frequency_time = VTime(0,0,10,0);
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1::externalFunction(const ExternalMessage &msg)
{
	if(msg.port() == start && isSet_in_port_volume)
	{
		this->on = true;
		holdIn(AtomicState::active, this->frequency_time);
	}
	else if(msg.port() == in_port_volume)
	{
		double x = Tuple<Real>::from_value(msg.value())[0].value();
		this->volume = x;
		isSet_in_port_volume = true;
	}
	else if(msg.port() == stop)
	{
		this->on = false;
		passivate();
	}

	return *this;
}


Model &PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1::internalFunction(const InternalMessage &)
{
	if(this->on)
		holdIn(AtomicState::active, this->frequency_time);
	else
		passivate();

	return *this ;
}


Model &PULSE_V_volume_FP_firstPulse_I_interval_flow1DEVS_BASIC_COUPLED_stock1::outputFunction(const CollectMessage &msg)
{
	auto random_int = this->volume;//this->dist(this->rng);
	Tuple<Real> out_value{Real(random_int)};
	sendOutput(msg.time(), out_port_PULSE_V_volume_FP_firstPulse_I_interval_flow1, out_value);
	return *this ;
}