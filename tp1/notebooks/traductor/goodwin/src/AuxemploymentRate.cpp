#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxemploymentRate.h"

using namespace std;

AuxemploymentRate::AuxemploymentRate(const string &name) :
	Atomic(name),
	in_populationIntegrator(addInputPort("in_populationIntegrator")),
	in_labor(addInputPort("in_labor")),
	isSet_populationIntegrator(false),
	isSet_labor(false),
	out(addOutputPort("out"))
{
}


Model &AuxemploymentRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxemploymentRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_populationIntegrator) {
		populationIntegrator = x;
		isSet_populationIntegrator = true;
	}
	if(msg.port() == in_labor) {
		labor = x;
		isSet_labor = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxemploymentRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxemploymentRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_populationIntegrator & isSet_labor ) {
		double val = labor / populationIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}