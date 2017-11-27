#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{model}}.h"

using namespace std;

{{model}}::{{model}}(const string &name) :
	Atomic(name),
	{% for var, port in params_ports.items() -%}
	{{port}}(addInputPort("{{port}}")),
	{% endfor -%}
	{% for var, port in params_ports.items() -%}
	isSet_{{var}}(false),
	{% endfor -%}
	out(addOutputPort("out"))
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

	{% for var, port in params_ports.items() -%}
	if(msg.port() == {{port}}) {
		{{var}} = x;
		isSet_{{var}} = true;
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
	if({% for var, port in params_ports.items() -%} 
		{% if loop.index0 == 0 %} isSet_{{var}} {% endif -%}
		{% if loop.index0 > 0 %}&& isSet_{{var}} {% endif -%}
	{% endfor -%}) {
		double val = {{function}};
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}
