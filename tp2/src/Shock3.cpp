#include <random>
#include <string>
#include <vector>

#include <math>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Shock3.h"

using namespace std;

Shock3::Shock3(const string &name) :
	Atomic(name),
	out(addOutputPort("out63")),
	out(addOutputPort("out81")),
	out(addOutputPort("out44")),
	out(addOutputPort("out04")),
	out(addOutputPort("out83")),
	out(addOutputPort("out91")),
	out(addOutputPort("out23")),
	out(addOutputPort("out01")),
	out(addOutputPort("out31")),
	out(addOutputPort("out54")),
	in(addInputPort("in")),
	numberOfOutputPorts(10),
	numberOfChosenOutputPorts(5),
	outValue(10)
{
}


Model &Shock3::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Shock3::externalFunction(const ExternalMessage &msg)
{
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Shock3::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Shock3::outputFunction(const CollectMessage &msg)
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
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out63, 10); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out81, 10); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out44, 10); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out04, 10); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out83, 10); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out91, 10); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out23, 10); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out01, 10); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out31, 10); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out54, 10); } 
	return *this ;
}