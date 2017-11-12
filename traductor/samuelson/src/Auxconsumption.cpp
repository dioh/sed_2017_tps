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
	in_marginalPropensitytoConsumealpha(addInputPort("in_marginalPropensitytoConsumealpha")),
	in_previousoutputIntegrator(addInputPort("in_previousoutputIntegrator")),
	isSet_marginalPropensitytoConsumealpha(false),
	isSet_previousoutputIntegrator(false),
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

	if(msg.port() == in_marginalPropensitytoConsumealpha) {
		marginalPropensitytoConsumealpha = x;
		isSet_marginalPropensitytoConsumealpha = true;
	}
	if(msg.port() == in_previousoutputIntegrator) {
		previousoutputIntegrator = x;
		isSet_previousoutputIntegrator = true;
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
	if( isSet_marginalPropensitytoConsumealpha & isSet_previousoutputIntegrator ) {
		double val = marginalPropensitytoConsumealpha * previousoutputIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}