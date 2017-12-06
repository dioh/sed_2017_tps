#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusLaborProductivitychgLaborProductivity.h"

using namespace std;

FplusLaborProductivitychgLaborProductivity::FplusLaborProductivitychgLaborProductivity(const string &name) :
	Atomic(name),
	in_laborProductivityIntegrator(addInputPort("in_laborProductivityIntegrator")),
	in_alphaChglaborProductivityIntegrator(addInputPort("in_alphaChglaborProductivityIntegrator")),
	isSet_laborProductivityIntegrator(false),
	isSet_alphaChglaborProductivityIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FplusLaborProductivitychgLaborProductivity::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusLaborProductivitychgLaborProductivity::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_laborProductivityIntegrator) {
		laborProductivityIntegrator = x;
		isSet_laborProductivityIntegrator = true;
	}
	if(msg.port() == in_alphaChglaborProductivityIntegrator) {
		alphaChglaborProductivityIntegrator = x;
		isSet_alphaChglaborProductivityIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusLaborProductivitychgLaborProductivity::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusLaborProductivitychgLaborProductivity::outputFunction(const CollectMessage &msg)
{
	if( isSet_laborProductivityIntegrator & isSet_alphaChglaborProductivityIntegrator ) {
		double val = laborProductivityIntegrator * alphaChglaborProductivityIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}