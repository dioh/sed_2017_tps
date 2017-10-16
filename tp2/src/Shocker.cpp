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
	out10(addOutputPort("out10")),
	out11(addOutputPort("out11")),
	out12(addOutputPort("out12")),
	out13(addOutputPort("out13")),
	out14(addOutputPort("out14")),
	out15(addOutputPort("out15")),
	out16(addOutputPort("out16")),
	out17(addOutputPort("out17")),
	out18(addOutputPort("out18")),
	out19(addOutputPort("out19")),
	in(addInputPort("in")),
	numberOfOutputPorts(20),
	numberOfChosenOutputPorts(10),
	outValue(3)
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
	vector<int> selected_ports(20);
	// Generate vector with indices of output ports used
	for(int i = 0; i < 20; i++) {
		if(i < 10) {
			selected_ports[i] = 1;
		} else {
			selected_ports[i] = 0;
		}
  	}
  	// Shuffle selected ports
  	for(int i = 20 - 1; i > 0; i--) {
	 	int j = rand() % i;
	 	swap(selected_ports[i], selected_ports[j]);
	}

	// Send output through rondomized group of output ports
	if(selected_ports[0] == 1) { sendOutput(msg.time(), out0, 3); } 
	if(selected_ports[1] == 1) { sendOutput(msg.time(), out1, 3); } 
	if(selected_ports[2] == 1) { sendOutput(msg.time(), out2, 3); } 
	if(selected_ports[3] == 1) { sendOutput(msg.time(), out3, 3); } 
	if(selected_ports[4] == 1) { sendOutput(msg.time(), out4, 3); } 
	if(selected_ports[5] == 1) { sendOutput(msg.time(), out5, 3); } 
	if(selected_ports[6] == 1) { sendOutput(msg.time(), out6, 3); } 
	if(selected_ports[7] == 1) { sendOutput(msg.time(), out7, 3); } 
	if(selected_ports[8] == 1) { sendOutput(msg.time(), out8, 3); } 
	if(selected_ports[9] == 1) { sendOutput(msg.time(), out9, 3); } 
	if(selected_ports[10] == 1) { sendOutput(msg.time(), out10, 3); } 
	if(selected_ports[11] == 1) { sendOutput(msg.time(), out11, 3); } 
	if(selected_ports[12] == 1) { sendOutput(msg.time(), out12, 3); } 
	if(selected_ports[13] == 1) { sendOutput(msg.time(), out13, 3); } 
	if(selected_ports[14] == 1) { sendOutput(msg.time(), out14, 3); } 
	if(selected_ports[15] == 1) { sendOutput(msg.time(), out15, 3); } 
	if(selected_ports[16] == 1) { sendOutput(msg.time(), out16, 3); } 
	if(selected_ports[17] == 1) { sendOutput(msg.time(), out17, 3); } 
	if(selected_ports[18] == 1) { sendOutput(msg.time(), out18, 3); } 
	if(selected_ports[19] == 1) { sendOutput(msg.time(), out19, 3); } 
	return *this ;
}