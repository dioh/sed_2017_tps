#include <random>
#include <string>
#include <vector>

#include <math>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Shock4.h"

using namespace std;

Shock4::Shock4(const string &name) :
	Atomic(name),
	out(addOutputPort("out72")),
	out(addOutputPort("out32")),
	out(addOutputPort("out14")),
	out(addOutputPort("out60")),
	out(addOutputPort("out62")),
	out(addOutputPort("out12")),
	out(addOutputPort("out82")),
	out(addOutputPort("out71")),
	out(addOutputPort("out53")),
	out(addOutputPort("out51")),
	in(addInputPort("in")),
	numberOfOutputPorts(10),
	numberOfChosenOutputPorts(5),
	outValue(10)
{
}


Model &Shock4::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Shock4::externalFunction(const ExternalMessage &msg)
{
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Shock4::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Shock4::outputFunction(const CollectMessage &msg)
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
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out72, 10); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out32, 10); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out14, 10); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out60, 10); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out62, 10); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out12, 10); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out82, 10); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out71, 10); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out53, 10); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out51, 10); } 
	return *this ;
}