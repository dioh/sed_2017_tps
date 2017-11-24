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
	in_prevOutptIntegrator(addInputPort("in_prevOutptIntegrator")),
	in_marginalPropensitytoConsumealpha(addInputPort("in_marginalPropensitytoConsumealpha")),
	isSet_prevOutptIntegrator(false),
	isSet_marginalPropensitytoConsumealpha(false),
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

	if(msg.port() == in_prevOutptIntegrator) {
		prevOutptIntegrator = x;
		isSet_prevOutptIntegrator = true;
	}
	if(msg.port() == in_marginalPropensitytoConsumealpha) {
		marginalPropensitytoConsumealpha = x;
		isSet_marginalPropensitytoConsumealpha = true;
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
	if( isSet_prevOutptIntegrator & isSet_marginalPropensitytoConsumealpha ) {
		double val = marginalPropensitytoConsumealpha * prevOutptIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}