#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{aux_name_lower}}.h"

using namespace std;

{{aux_name_lower}}::{{aux_name_lower}}(const string &name) :
	Atomic(name),
	{%- for input_port_name in input_ports %}
    {{input_port_name}}(addInputPort("{{input_port_name}}")),
    {%- endfor -%}
	{%- for input_port_name in input_ports %}
    isSet_{{input_port_name}}(false),
    {%- endfor %}
	{{aux_name_lower}}(addOutputPort("{{aux_name_lower}}"))
{
}


Model &{{aux_name_lower}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{aux_name_lower}}::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	{% for input_port_name in input_ports -%}
	if(msg.port() == {{input_port_name}}) {
		{{input_port_name}} = x;
		isSet_{{input_port_name}} = true;
	}
	{% endfor -%}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &{{aux_name_lower}}::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &{{aux_name_lower}}::outputFunction(const CollectMessage &msg)
{
	{% if input_ports|length > 0 %}
	if({% for input_port_name in input_ports -%}
		{% if loop.index0 == 0 %} isSet_{{input_port_name}} {% endif -%}
		{% if loop.index0 > 0 %}& isSet_{{input_port_name}} {% endif -%}
	{% endfor -%}) {
	    Tuple<Real> out_value { {{equation}} };
		sendOutput(msg.time(), {{aux_name_lower}}, out_value);
	}
	{% endif %}
	return *this ;
}
