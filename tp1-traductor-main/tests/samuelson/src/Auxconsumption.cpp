#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxconsumption.h"

using namespace std;

Auxconsumption::Auxconsumption(const string &name) :
	Atomic(name),
	in_MarginalPropensitytoConsumealpha(addInputPort("in_MarginalPropensitytoConsumealpha")),
	in_previousOutputIntegrator(addInputPort("in_previousOutputIntegrator")),
	isSet_MarginalPropensitytoConsumealpha(false),
	isSet_previousOutputIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &Auxconsumption::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxconsumption::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_MarginalPropensitytoConsumealpha) {
		MarginalPropensitytoConsumealpha = x;
		isSet_MarginalPropensitytoConsumealpha = true;
	}
	if(msg.port() == in_previousOutputIntegrator) {
		previousOutputIntegrator = x;
		isSet_previousOutputIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxconsumption::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxconsumption::outputFunction(const CollectMessage &msg)
{
	if( isSet_MarginalPropensitytoConsumealpha & isSet_previousOutputIntegrator ) {
		double val = Marginal Propensity to Consume alpha * previousOutputIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}