#include <random>
#include <string>
#include <vector>

#include <math>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{atomicClass}}.h"

using namespace std;

{{atomicClass}}::{{atomicClass}}(const string &name) :
	Atomic(name),
	{% for outPort in outPorts -%}
	out(addOutputPort("{{outPort}}")),
	{% endfor -%}
	in(addInputPort("in")),
	numberOfOutputPorts({{numberOfOutputPorts}}),
	numberOfChosenOutputPorts({{numberOfChosenOutputPorts}}),
	outValue({{outValue}})
{
}


Model &{{atomicClass}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{atomicClass}}::externalFunction(const ExternalMessage &msg)
{
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
	vector<int> selected_ports({{numberOfOutputPorts}});
	// Generate vector with indices of output ports used
	for(int i = 0; i < {{numberOfOutputPorts}}; i++) {
		if(i < {{numberOfChosenOutputPorts}}) {
			selected_ports[i] = 1;
		} else {
			selected_ports[i] = 0;
		}
  	}
  	// Shuffle selected ports
  	for(i = {{numberOfOutputPorts}} - 1; i > 0; i--) {
	 	j = rand() % i;
	 	swap(selected_ports[i], selected_ports[j]);
	}

	// Send output through rondomized group of output ports
	{% for outPort in outPorts -%} 
		if(selected_ports[{{loop.index - 1}}] == 1) { sendOutput(msg.time(), {{outPort}}, {{outValue}}); } 
	{% endfor -%}
	return *this ;
}
