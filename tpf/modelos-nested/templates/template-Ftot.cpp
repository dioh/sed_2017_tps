#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{tot_name_lower}}.h"

using namespace std;

{{tot_name_lower}}::{{tot_name_lower}}(const string &name) :
	Atomic(name),
	{% for port_plus in plus_input_ports -%}
	{{port_plus}}(addInputPort("{{port_plus}}")),
	{% endfor -%}
	{% for port_minus in minus_input_ports -%}
	{{port_minus}}(addInputPort("{{port_minus}}")),
	{% endfor -%}
	{% for port_plus in plus_input_ports -%}
	isSet_{{port_plus}}(false),
	{% endfor -%}
	{% for port_minus in minus_input_ports -%}
	isSet_{{port_minus}}(false),
	{% endfor -%}
	{% for port_out in output_ports -%}
	{{port_out}}(addOutputPort("{{port_out}}"))
	{% endfor -%}
{
}


Model &{{tot_name_lower}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{tot_name_lower}}::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	{% for port_plus in plus_input_ports -%}
	if(msg.port() == {{port_plus}}) {
		{{port_plus}} = x;
		isSet_{{port_plus}} = true;
	}
	{% endfor -%}
	{% for port_minus in minus_input_ports -%}
	if(msg.port() == {{port_minus}}) {
		{{port_minus}} = x;
		isSet_{{port_minus}} = true;
	}
	{% endfor -%}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &{{tot_name_lower}}::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &{{tot_name_lower}}::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if({%- for port_plus in plus_input_ports -%} 
	{%- if loop.index0 == 0 %}isSet_{{port_plus}} {%- endif -%}
	{%- if loop.index0 > 0 %}& isSet_{{port_plus}} 
	{%- endif -%}
	{%- endfor -%}
	{%- for port_minus in minus_input_ports -%}
	{%- if loop.index0 == 0 and plus_input_ports|length == 0 %}isSet_{{port_minus}}
	{%- endif %}
	{%- if loop.index0 > 0 or (loop.index0 == 0 and plus_input_ports|length > 0) %} & isSet_{{port_minus}}
	{%- endif %}
	{%- endfor -%}
	) {
		{% for port_plus in plus_input_ports -%}
		plus = plus + {{port_plus}};
		{% endfor -%}
		{% for port_minus in minus_input_ports -%}
		minus = minus + {{port_minus}};
		{% endfor -%}
		double val = plus - minus;
		Tuple<Real> out_value { val };
		{% for port_out in output_ports -%}
		sendOutput(msg.time(), {{port_out}}, out_value);
		{% endfor -%}
	}

	return *this ;
}
