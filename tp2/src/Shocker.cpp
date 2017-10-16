#include <random>
#include <string>
#include <vector>

#include "math.h"

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Shocker.h"

using namespace std;

Shocker::Shocker(const string &name) :
	Atomic(name),
	out0(addOutputPort("out0")),
	out1(addOutputPort("out1")),
	out2(addOutputPort("out2")),
	out3(addOutputPort("out3")),
	out4(addOutputPort("out4")),
	out5(addOutputPort("out5")),
	out6(addOutputPort("out6")),
	out7(addOutputPort("out7")),
	out8(addOutputPort("out8")),
	out9(addOutputPort("out9")),
	in(addInputPort("in")),
	numberOfOutputPorts(10),
	numberOfChosenOutputPorts(5),
	outValue(10)
{
}


Model &Shocker::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Shocker::externalFunction(const ExternalMessage &msg)
{
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Shocker::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Shocker::outputFunction(const CollectMessage &msg)
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
  	for(int i = 10 - 1; i > 0; i--) {
	 	int j = rand() % i;
	 	swap(selected_ports[i], selected_ports[j]);
	}

	// Send output through rondomized group of output ports
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out0, 10); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out1, 10); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out2, 10); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out3, 10); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out4, 10); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out5, 10); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out6, 10); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out7, 10); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out8, 10); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out9, 10); } 
	return *this ;
}