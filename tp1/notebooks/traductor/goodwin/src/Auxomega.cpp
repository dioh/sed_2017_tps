#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxomega.h"

using namespace std;

Auxomega::Auxomega(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_wages(addInputPort("in_wages")),
	isSet_output(false),
	isSet_wages(false),
	out(addOutputPort("out"))
{
}


Model &Auxomega::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxomega::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_wages) {
		wages = x;
		isSet_wages = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxomega::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxomega::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_wages ) {
		double val = wages / output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}