#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusRecovered.h"

using namespace std;

FplusRecovered::FplusRecovered(const string &name) :
	Atomic(name),
	inInfectiousIntegrator(addInputPort("inInfectiousIntegrator")),
	inDuration(addInputPort("inDuration")),
	isSetInfectiousIntegrator(false),
	isSetDuration(false),
	out(addOutputPort("out"))
{
}


Model &FplusRecovered::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusRecovered::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inInfectiousIntegrator) {
		infectiousIntegrator = x;
		isSetInfectiousIntegrator = true;
	}
	if(msg.port() == inDuration) {
		duration = x;
		isSetDuration = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusRecovered::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusRecovered::outputFunction(const CollectMessage &msg)
{
	if( isSetInfectiousIntegrator && isSetDuration ) {
		double val = infectiousIntegrator/duration;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}