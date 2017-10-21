#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "{{stockName}}.h"

using namespace std;

{{stockName}}::{{stockName}}(const string &name) :
	Atomic(name),
	{% for inPort in inPorts -%}
	{{inPort}}(addInputPort("{{inPort}}")),
	{% endfor -%}
	{% for setVar in setVariables -%}
	{{setVar}}(false),
	{% endfor -%}
	out(addOutputPort("out"))
{
}


Model &{{stockName}}::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &{{stockName}}::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	{% for var in variables -%}
	if(msg.port() == {{inPorts[loop.index0]}}) {
		{{variables[loop.index0]}} = x;
		{{setVariables[loop.index0]}} = true;
	}
	{% endfor -%}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &{{stockName}}::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &{{stockName}}::outputFunction(const CollectMessage &msg)
{
	if( {% for setVar in setVariables -%}
		{% if loop.index0 == 0 -%} {{setVar}} {% endif-%}
		{% if loop.index0 != 0 -%} && {{setVar}} {% endif-%}
	  {% endfor -%}) {
		double val = {{formula}};
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}
