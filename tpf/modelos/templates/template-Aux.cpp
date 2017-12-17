#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{name}}.h"

using namespace std;

{{name}}::{{name}}(const string &name) :
	Atomic(name),
	{% for port_name in aux_inPorts -%}
	{{port_name}}(addInputPort("{{port_name}}")),
	{% endfor -%}
	{% for val in values -%}
	isSet_{{val}}(false),
	{% endfor -%}
	out(addOutputPort("out"))
{
}


Model &{{name}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{name}}::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	{% for port_name in aux_inPorts -%}
	if(msg.port() == {{port_name}}) {
		{{values[loop.index0]}} = x;
		isSet_{{values[loop.index0]}} = true;
	}
	{% endfor -%}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &{{name}}::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &{{name}}::outputFunction(const CollectMessage &msg)
{
	if({% for port_name in aux_inPorts -%} 
		{% if loop.index0 == 0 %} isSet_{{values[loop.index0]}} {% endif -%}
		{% if loop.index0 > 0 %}& isSet_{{values[loop.index0]}} {% endif -%}
	{% endfor -%}) {
		double val = {{function}};
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}
