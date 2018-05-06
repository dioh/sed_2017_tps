#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1.h"

using namespace std;


PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1::PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1(const string &name) :
	Atomic(name),
	in_port_start(addInputPort("in_port_start")),
	in_port_volumeX(addInputPort("in_port_volumeX")),
    isSet_volume(false),
    in_port_intervalX(addInputPort("in_port_intervalX")),
    isSet_interval(false),
    stop(addInputPort("stop")), 
	out(addOutputPort("out")),
	//frequency_time(0,0,10,0),
	on(true),
	dist(0,100),
	rng(random_device()()),
	out_port_PULSE_V_volumeX_I_intervalX_flow1(addOutputPort("out_port_PULSE_V_volumeX_I_intervalX_flow1"))
{
}


Model &PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1::initFunction()
{
	//holdIn(AtomicState::active, this->frequency_time);
	// TODO : get frequency_time parameters from get_params in .ma file
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	// Requiere que cuando llega el 'start', ya esten seteados el 'interval' y el 'volume'
	if(msg.port() == in_port_start && isSet_volume && isSet_interval)
	{
		this->frequency_time = VTime(0,0,this->intervalX,0);
		this->on = true;
		holdIn(AtomicState::active, this->frequency_time);
	}
	else if(msg.port() == in_port_volumeX)
	{
		isSet_volume = true;
		this->volumeX = x;
	}
	else if(msg.port() == in_port_intervalX)
	{
		isSet_interval = true;
		this->intervalX = x;
	}
	else if(msg.port() == stop)
	{
		this->on = false;
		passivate();
	}

	return *this;
}


Model &PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1::internalFunction(const InternalMessage &)
{
	if(this->on)
		holdIn(AtomicState::active, this->frequency_time);
	else
		passivate();

	return *this ;
}


Model &PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1::outputFunction(const CollectMessage &msg)
{
	auto random_int = this->volumeX;//this->dist(this->rng);
	Tuple<Real> out_value{Real(random_int)};
	sendOutput(msg.time(), out_port_PULSE_V_volumeX_I_intervalX_flow1, out_value);
	return *this ;
}