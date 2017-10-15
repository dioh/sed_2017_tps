#include <random>
#include <string>
#include <vector>

#include <math>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Shock2.h"

using namespace std;

Shock2::Shock2(const string &name) :
	Atomic(name),
	out(addOutputPort("out50")),
	out(addOutputPort("out34")),
	out(addOutputPort("out84")),
	out(addOutputPort("out33")),
	out(addOutputPort("out11")),
	out(addOutputPort("out73")),
	out(addOutputPort("out64")),
	out(addOutputPort("out21")),
	out(addOutputPort("out30")),
	out(addOutputPort("out22")),
	in(addInputPort("in")),
	numberOfOutputPorts(10),
	numberOfChosenOutputPorts(5),
	outValue(10)
{
}


Model &Shock2::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Shock2::externalFunction(const ExternalMessage &msg)
{
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Shock2::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Shock2::outputFunction(const CollectMessage &msg)
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
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out50, 10); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out34, 10); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out84, 10); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out33, 10); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out11, 10); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out73, 10); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out64, 10); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out21, 10); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out30, 10); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out22, 10); } 
	return *this ;
}