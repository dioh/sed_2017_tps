#include <random>
#include <string>
#include <vector>

#include <math>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Shock0.h"

using namespace std;

Shock0::Shock0(const string &name) :
	Atomic(name),
	out(addOutputPort("out61")),
	out(addOutputPort("out93")),
	out(addOutputPort("out03")),
	out(addOutputPort("out80")),
	out(addOutputPort("out13")),
	out(addOutputPort("out00")),
	out(addOutputPort("out20")),
	out(addOutputPort("out52")),
	out(addOutputPort("out10")),
	out(addOutputPort("out92")),
	in(addInputPort("in")),
	numberOfOutputPorts(10),
	numberOfChosenOutputPorts(5),
	outValue(10)
{
}


Model &Shock0::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Shock0::externalFunction(const ExternalMessage &msg)
{
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Shock0::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Shock0::outputFunction(const CollectMessage &msg)
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
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out61, 10); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out93, 10); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out03, 10); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out80, 10); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out13, 10); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out00, 10); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out20, 10); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out52, 10); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out10, 10); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out92, 10); } 
	return *this ;
}