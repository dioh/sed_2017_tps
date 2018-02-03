#include <random>
#include <string>
#include <vector>

#include "math.h"

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{atomicClass}}.h"

using namespace std;

{{atomicClass}}::{{atomicClass}}(const string &name) :
	Atomic(name),
	{% for outPort in outPorts -%}
	{{outPort}}(addOutputPort("{{outPort}}")),
	{% endfor -%}
	in(addInputPort("in")),
	numberOfOutputPorts({{numberOfOutputPorts}}),
	numberOfChosenOutputPorts({{numberOfChosenOutputPorts}})
{
}


Model &{{atomicClass}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{atomicClass}}::externalFunction(const ExternalMessage &msg)
{
	shockValue = Tuple<Real>::from_value(msg.value())[0];
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &{{atomicClass}}::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &{{atomicClass}}::outputFunction(const CollectMessage &msg)
{
	srand(time(0));

	vector<int> selected_ports;
	// Generate vector with indices of output ports used
	for(int i = 0; i < {{numberOfOutputPorts}}; i++) {
		if(i < {{numberOfChosenOutputPorts}}) {
			selected_ports.push_back(1);
		} else {
			selected_ports.push_back(0);
		}
  	}
  	// Shuffle selected ports
  	std::random_shuffle ( selected_ports.begin(), selected_ports.end() );

	// Send output through rondomized group of output ports
	{% for outPort in outPorts -%} 
		if(selected_ports[{{loop.index - 1}}] == 1) { sendOutput(msg.time(), {{outPort}}, shockValue); } 
	{% endfor -%}
	return *this ;
}
