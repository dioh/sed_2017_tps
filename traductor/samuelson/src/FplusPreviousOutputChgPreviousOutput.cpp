#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPreviousOutputChgPreviousOutput.h"

using namespace std;

FplusPreviousOutputChgPreviousOutput::FplusPreviousOutputChgPreviousOutput(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_twounitTimestep(addInputPort("in_twounitTimestep")),
	in_previousoutputIntegrator(addInputPort("in_previousoutputIntegrator")),
	isSet_output(false),
	isSet_twounitTimestep(false),
	isSet_previousoutputIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FplusPreviousOutputChgPreviousOutput::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPreviousOutputChgPreviousOutput::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_twounitTimestep) {
		twounitTimestep = x;
		isSet_twounitTimestep = true;
	}
	if(msg.port() == in_previousoutputIntegrator) {
		previousoutputIntegrator = x;
		isSet_previousoutputIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPreviousOutputChgPreviousOutput::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPreviousOutputChgPreviousOutput::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_twounitTimestep & isSet_previousoutputIntegrator ) {
		double val = (output - previousoutputIntegrator) / twounitTimestep;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}