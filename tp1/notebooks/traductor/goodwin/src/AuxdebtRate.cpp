#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxdebtRate.h"

using namespace std;

AuxdebtRate::AuxdebtRate(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_debtIntegrator(addInputPort("in_debtIntegrator")),
	isSet_output(false),
	isSet_debtIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &AuxdebtRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxdebtRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_debtIntegrator) {
		debtIntegrator = x;
		isSet_debtIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxdebtRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxdebtRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_debtIntegrator ) {
		double val = debtIntegrator / output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}