#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPredatorPlusPredator.h"

using namespace std;

FplusPredatorPlusPredator::FplusPredatorPlusPredator(const string &name) :
	Atomic(name),
	in_predatorIntegrator(addInputPort("in_predatorIntegrator")),
	in_preyIntegrator(addInputPort("in_preyIntegrator")),
	isSet_predatorIntegrator(false),
	isSet_preyIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FplusPredatorPlusPredator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPredatorPlusPredator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_predatorIntegrator) {
		predatorIntegrator = x;
		isSet_predatorIntegrator = true;
	}
	if(msg.port() == in_preyIntegrator) {
		preyIntegrator = x;
		isSet_preyIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPredatorPlusPredator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPredatorPlusPredator::outputFunction(const CollectMessage &msg)
{
	if( isSet_predatorIntegrator & isSet_preyIntegrator ) {
		double val = 0.01 * preyIntegrator * predatorIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}