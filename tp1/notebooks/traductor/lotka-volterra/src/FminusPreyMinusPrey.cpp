#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusPreyMinusPrey.h"

using namespace std;

FminusPreyMinusPrey::FminusPreyMinusPrey(const string &name) :
	Atomic(name),
	in_predatorIntegrator(addInputPort("in_predatorIntegrator")),
	in_preyIntegrator(addInputPort("in_preyIntegrator")),
	isSet_predatorIntegrator(false),
	isSet_preyIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FminusPreyMinusPrey::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusPreyMinusPrey::externalFunction(const ExternalMessage &msg)
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


Model &FminusPreyMinusPrey::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusPreyMinusPrey::outputFunction(const CollectMessage &msg)
{
	if( isSet_predatorIntegrator & isSet_preyIntegrator ) {
		double val = 0.02 * preyIntegrator * predatorIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}