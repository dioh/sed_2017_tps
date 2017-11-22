#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusRecoveredRecovering.h"

using namespace std;

FplusRecoveredRecovering::FplusRecoveredRecovering(const string &name) :
	Atomic(name),
	in_infectiousIntegrator(addInputPort("in_infectiousIntegrator")),
	in_duration(addInputPort("in_duration")),
	isSet_infectiousIntegrator(false),
	isSet_duration(false),
	out(addOutputPort("out"))
{
}


Model &FplusRecoveredRecovering::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusRecoveredRecovering::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_infectiousIntegrator) {
		infectiousIntegrator = x;
		isSet_infectiousIntegrator = true;
	}
	if(msg.port() == in_duration) {
		duration = x;
		isSet_duration = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusRecoveredRecovering::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusRecoveredRecovering::outputFunction(const CollectMessage &msg)
{
	if( isSet_infectiousIntegrator & isSet_duration ) {
		double val = infectiousIntegrator/duration;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}