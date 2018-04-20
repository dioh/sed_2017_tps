#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "pulse.h"

using namespace std;


Pulse::Pulse(const string &name) :
	Atomic(name),
	start(addInputPort("start")),
	stop(addInputPort("stop")), 
	input(addInputPort("input")),
	out(addOutputPort("out")),
	frequency_time(0,0,1,0),
	value(0)
{
}


Model &Pulse::initFunction()
{
	passivate();
	return *this;
}


Model &Pulse::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == start){
		holdIn(AtomicState::active, VTime::Zero);
	}else if(msg.port() == stop){
		passivate();
	}else if(msg.port() == input){
		this->value = x;
	}

	return *this;
}


Model &Pulse::internalFunction(const InternalMessage &)
{
	holdIn(AtomicState::active, this->frequency_time);
	return *this ;
}


Model &Pulse::outputFunction(const CollectMessage &msg)
{
	Tuple<Real> out_value {Real(this->value)};
	sendOutput(msg.time(), out, out_value);
	return *this ;
}
