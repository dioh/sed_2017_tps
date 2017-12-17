#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxlabor.h"

using namespace std;

Auxlabor::Auxlabor(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_laborProductivityIntegrator(addInputPort("in_laborProductivityIntegrator")),
	isSet_output(false),
	isSet_laborProductivityIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &Auxlabor::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxlabor::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_laborProductivityIntegrator) {
		laborProductivityIntegrator = x;
		isSet_laborProductivityIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxlabor::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxlabor::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_laborProductivityIntegrator ) {
		double val = output / laborProductivityIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}