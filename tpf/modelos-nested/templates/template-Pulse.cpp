#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{pulse_name_lower}}.h"

using namespace std;


{{pulse_name_lower}}::{{pulse_name_lower}}(const string &name) :
	Atomic(name),
	in_port_start(addInputPort("in_port_start")),
	{% if volume_param != None -%}
    volume({{volume_param}}),
    isSet_volume(true),
    {% endif -%}
    {% if interval_param != None -%}
    interval({{interval_param}}),
    isSEt_interval(true),
    {% endif -%}
    {% if volume_input != None -%}
    in_port_{{volume_input}}(addInputPort("in_port_{{volume_input}}")),
    isSet_volume(false),
    {% endif -%}
    {% if interval_input != None -%}
    in_port_{{interval_input}}(addInputPort("in_port_{{interval_input}}")),
    isSet_interval(false),
    {% endif -%}
	stop(addInputPort("stop")), 
	out(addOutputPort("out")),
	//frequency_time(0,0,10,0),
	on(true),
	dist(0,100),
	rng(random_device()()),
	out_port_{{pulse_name}}(addOutputPort("out_port_{{pulse_name}}"))
{
}


Model &{{pulse_name_lower}}::initFunction()
{
	//holdIn(AtomicState::active, this->frequency_time);
	// TODO : get frequency_time parameters from get_params in .ma file
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{pulse_name_lower}}::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	// Requiere que cuando llega el 'start', ya esten seteados el 'interval' y el 'volume'
	if(msg.port() == in_port_start && isSet_volume && isSet_interval)
	{
		{% if interval_param != None -%}
		this->frequency_time = VTime(0,0,this->interval,0);
		{% endif -%}
		{% if interval_input != None -%}
		this->frequency_time = VTime(0,0,this->{{interval_input}},0);
		{% endif -%}
		this->on = true;
		holdIn(AtomicState::active, this->frequency_time);
	}
	{% if volume_input != None -%}
	else if(msg.port() == in_port_{{volume_input}})
	{
		isSet_volume = true;
		this->{{volume_input}} = x;
	}
	{% endif -%}
	{% if interval_input != None -%}
	else if(msg.port() == in_port_{{interval_input}})
	{
		isSet_interval = true;
		this->{{interval_input}} = x;
	}
	{% endif -%}
	else if(msg.port() == stop)
	{
		this->on = false;
		passivate();
	}

	return *this;
}


Model &{{pulse_name_lower}}::internalFunction(const InternalMessage &)
{
	if(this->on)
		holdIn(AtomicState::active, this->frequency_time);
	else
		passivate();

	return *this ;
}


Model &{{pulse_name_lower}}::outputFunction(const CollectMessage &msg)
{
	{% if volume_param != None -%}
	auto random_int = this->volume;//this->dist(this->rng);
	{% endif -%}
	{% if volume_input != None -%}
	auto random_int = this->{{volume_input}};//this->dist(this->rng);
	{% endif -%}
	Tuple<Real> out_value{Real(random_int)};
	sendOutput(msg.time(), out_port_{{pulse_name}}, out_value);
	return *this ;
}
