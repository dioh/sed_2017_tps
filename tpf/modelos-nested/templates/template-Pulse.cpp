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
	start(addInputPort("start")),
	stop(addInputPort("stop")), 
	out(addOutputPort("out")),
	frequency_time(0,0,10,0),
	on(true),
	dist(0,100),
	rng(random_device()()),
	out_port_{{pulse_name}}(addOutputPort("out_port_{{pulse_name}}"))
{
}


Model &{{pulse_name_lower}}::initFunction()
{
	holdIn(AtomicState::active, this->frequency_time);
	return *this;
}


Model &{{pulse_name_lower}}::externalFunction(const ExternalMessage &msg)
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
	auto random_int = -50;//this->dist(this->rng);
	Tuple<Real> out_value{Real(random_int)};
	sendOutput(msg.time(), out_port_{{pulse_name}}, out_value);
	return *this ;
}
