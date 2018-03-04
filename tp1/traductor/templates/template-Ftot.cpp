#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{model}}.h"

using namespace std;

{{model}}::{{model}}(const string &name) :
	{% for inPort in ft_inPorts -%}
	{{inPort}}(addInputPort("{{inPort}}")),
	{% endfor -%}
	{% for outPort in ft_outPorts -%}
	{{outPort}}(addOutputPort("{{outPort}}")),
	{% endfor -%}
	{% for inPort in ft_inPorts -%}
	val_{{inPort}}(0),
	{% endfor -%}
	{% for inPort in ft_inPorts -%}
    isSet_val_{{inPort}}(false),
	{% endfor -%}
    Atomic(name)
{
}


Model &{{model}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{model}}::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	{% for inPort in ft_inPorts -%}
	if(msg.port() == {{inPort}}) {
		val_{{inPort}} = x;
		isSet_val_{{inPort}} = true;
	}
	{% endfor -%}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &{{model}}::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &{{model}}::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if({% for inPort in ft_inPorts -%} 
		{% if loop.index0 == 0 %} isSet_val_{{inPort}} {% endif -%}
		{% if loop.index0 > 0 %}&& isSet_val_{{inPort}} {% endif -%}
	{% endfor -%}) {
		{% for inPort in ft_inPorts -%}
		{% if 'inPlus' in inPort -%}
		plus = plus + val_{{inPort}};
		{% endif -%}
		{% if 'inMinus' in inPort -%}
		minus = minus + val_{{inPort}};
		{% endif -%}
		{% endfor -%}
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}
