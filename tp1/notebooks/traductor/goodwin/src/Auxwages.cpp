#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxwages.h"

using namespace std;

Auxwages::Auxwages(const string &name) :
	Atomic(name),
	in_wageRateIntegrator(addInputPort("in_wageRateIntegrator")),
	in_labor(addInputPort("in_labor")),
	isSet_wageRateIntegrator(false),
	isSet_labor(false),
	out(addOutputPort("out"))
{
}


Model &Auxwages::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxwages::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_wageRateIntegrator) {
		wageRateIntegrator = x;
		isSet_wageRateIntegrator = true;
	}
	if(msg.port() == in_labor) {
		labor = x;
		isSet_labor = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxwages::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxwages::outputFunction(const CollectMessage &msg)
{
	if( isSet_wageRateIntegrator & isSet_labor ) {
		double val = wageRateIntegrator * labor;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}