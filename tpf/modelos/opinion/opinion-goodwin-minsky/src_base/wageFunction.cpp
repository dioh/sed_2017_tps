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
	employmentRateValue(addInputPort("employmentRateValue")),
	employmentRateZero(addInputPort("employmentRateZero")),
	employmentRateStable(addInputPort("employmentRateStable")),
	isSet_val_employmentRateValue(false),
	isSet_val_employmentRateZero(false),
	isSet_val_employmentRateStable(false),
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

	if(msg.port() == employmentRateValue) {
		val_employmentRateValue = x;
		isSet_val_employmentRateValue = true;
	}
	if(msg.port() == employmentRateZero) {
		val_employmentRateZero = x;
		isSet_val_employmentRateZero = true;
	}
	if(msg.port() == employmentRateStable) {
		val_employmentRateStable = x;
		isSet_val_employmentRateStable = true;
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
	if( isSet_val_employmentRateValue & isSet_val_employmentRateZero & isSet_val_employmentRateStable ) {
		double val = (val_employmentRateValue - val_employmentRateZero) * val_employmentRateStable;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}