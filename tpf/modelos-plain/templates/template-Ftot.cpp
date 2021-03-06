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
	{% for port_plus in in_ports_plus -%}
	{{port_plus['name']}}(addInputPort("{{port_plus['name']}}")),
	{% endfor -%}
	{% for port_minus in in_ports_minus -%}
	{{port_minus['name']}}(addInputPort("{{port_minus['name']}}")),
	{% endfor -%}
	{% for port_plus in in_ports_plus -%}
	isSet_val_{{port_plus['name']}}(false),
	{% endfor -%}
	{% for port_minus in in_ports_minus -%}
	isSet_val_{{port_minus['name']}}(false),
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

	{% for port_plus in in_ports_plus -%}
	if(msg.port() == {{port_plus['name']}}) {
		val_{{port_plus['name']}} = x;
		isSet_val_{{port_plus['name']}} = true;
	}
	{% endfor -%}
	{% for port_minus in in_ports_minus -%}
	if(msg.port() == {{port_minus['name']}}) {
		val_{{port_minus['name']}} = x;
		isSet_val_{{port_minus['name']}} = true;
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
	double plus = 0;
	double minus = 0;
	if({%- for port_plus in in_ports_plus -%} 
	{%- if loop.index0 == 0 %}isSet_val_{{port_plus['name']}} {%- endif -%}
	{%- if loop.index0 > 0 %}& isSet_val_{{port_plus['name']}} 
	{%- endif -%}
	{%- endfor -%}
	{%- for port_minus in in_ports_minus -%}
	{%- if loop.index0 == 0 and in_ports_plus|length == 0 %}isSet_val_{{port_minus['name']}}
	{%- endif %}
	{%- if loop.index0 > 0 or (loop.index0 == 0 and in_ports_plus|length > 0) %} & isSet_val_{{port_minus['name']}}
	{%- endif %}
	{%- endfor -%}
	) {
		{% for port_plus in in_ports_plus -%}
		plus = plus + val_{{port_plus['name']}};
		{% endfor -%}
		{% for port_minus in in_ports_minus -%}
		minus = minus + val_{{port_minus['name']}};
		{% endfor -%}
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}
