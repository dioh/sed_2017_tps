#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "wageFunction.h"

using namespace std;

wageFunction::wageFunction(const string &name) :
	Atomic(name),
	employmentRateStable(addInputPort("employmentRateStable")),
	employmentRateValue(addInputPort("employmentRateValue")),
	employmentRateZero(addInputPort("employmentRateZero")),
	isSet_val_employmentRateStable(false),
	isSet_val_employmentRateValue(false),
	isSet_val_employmentRateZero(false),
	out(addOutputPort("out"))
{
}


Model &wageFunction::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &wageFunction::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == employmentRateStable) {
		val_employmentRateStable = x;
		isSet_val_employmentRateStable = true;
	}
	if(msg.port() == employmentRateValue) {
		val_employmentRateValue = x;
		isSet_val_employmentRateValue = true;
	}
	if(msg.port() == employmentRateZero) {
		val_employmentRateZero = x;
		isSet_val_employmentRateZero = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &wageFunction::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &wageFunction::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_employmentRateStable & isSet_val_employmentRateValue & isSet_val_employmentRateZero ) {
		double val = (val_employmentRateStable*(val_employmentRateValue-val_employmentRateZero));
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}