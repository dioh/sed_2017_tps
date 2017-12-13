#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusPredatorMinusPredator.h"

using namespace std;

FminusPredatorMinusPredator::FminusPredatorMinusPredator(const string &name) :
	Atomic(name),
	in_predatorIntegrator(addInputPort("in_predatorIntegrator")),
	isSet_predatorIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FminusPredatorMinusPredator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusPredatorMinusPredator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_predatorIntegrator) {
		predatorIntegrator = x;
		isSet_predatorIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusPredatorMinusPredator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusPredatorMinusPredator::outputFunction(const CollectMessage &msg)
{
	if( isSet_predatorIntegrator ) {
		double val = 0.3 * predatorIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}