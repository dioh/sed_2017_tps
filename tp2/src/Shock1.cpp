#include <random>
#include <string>
#include <vector>

#include <math>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Shock1.h"

using namespace std;

Shock1::Shock1(const string &name) :
	Atomic(name),
	out(addOutputPort("out02")),
	out(addOutputPort("out74")),
	out(addOutputPort("out41")),
	out(addOutputPort("out43")),
	out(addOutputPort("out90")),
	out(addOutputPort("out24")),
	out(addOutputPort("out94")),
	out(addOutputPort("out40")),
	out(addOutputPort("out42")),
	out(addOutputPort("out70")),
	in(addInputPort("in")),
	numberOfOutputPorts(10),
	numberOfChosenOutputPorts(5),
	outValue(10)
{
}


Model &Shock1::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Shock1::externalFunction(const ExternalMessage &msg)
{
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Shock1::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Shock1::outputFunction(const CollectMessage &msg)
{
	vector<int> selected_ports(10);
	// Generate vector with indices of output ports used
	for(int i = 0; i < 10; i++) {
		if(i < 5) {
			selected_ports[i] = 1;
		} else {
			selected_ports[i] = 0;
		}
  	}
  	// Shuffle selected ports
  	for(i = 10 - 1; i > 0; i--) {
	 	j = rand() % i;
	 	swap(selected_ports[i], selected_ports[j]);
	}

	// Send output through rondomized group of output ports
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out02, 10); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out74, 10); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out41, 10); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out43, 10); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out90, 10); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out24, 10); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out94, 10); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out40, 10); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out42, 10); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out70, 10); } 
	return *this ;
}