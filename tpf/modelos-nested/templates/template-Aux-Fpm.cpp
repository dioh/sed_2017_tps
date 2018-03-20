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
	{% for in_port in in_ports -%}
	{{in_port['name']}}(addInputPort("{{in_port['name']}}")),
	{% endfor -%}
	{% for in_port in in_ports -%}
	isSet_val_{{in_port['name']}}(false),
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

	{% for in_port in in_ports -%}
	if(msg.port() == {{in_port['name']}}) {
		val_{{in_port['name']}} = x;
		isSet_val_{{in_port['name']}} = true;
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
	{% if in_ports|length > 0 %}
	if({% for in_port in in_ports -%}
		{% if loop.index0 == 0 %} isSet_val_{{in_port['name']}} {% endif -%}
		{% if loop.index0 > 0 %}& isSet_val_{{in_port['name']}} {% endif -%}
	{% endfor -%}) {
		double val = {{parameters[0]['function']}};
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	{% endif %}
	return *this ;
}
