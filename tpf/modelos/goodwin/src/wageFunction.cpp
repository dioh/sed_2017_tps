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
	in_employmentRate(addInputPort("in_employmentRate")),
	in_employmentRateZero(addInputPort("in_employmentRateZero")),
	in_employmentRateStable(addInputPort("in_employmentRateStable")),
	isSet_employmentRate(false),
	isSet_employmentRateZero(false),
	isSet_employmentRateStable(false),
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

	if(msg.port() == in_employmentRate) {
		employmentRate = x;
		isSet_employmentRate = true;
	}
	if(msg.port() == in_employmentRateZero) {
		employmentRateZero = x;
		isSet_employmentRateZero = true;
	}
	if(msg.port() == in_employmentRateStable) {
		employmentRateStable = x;
		isSet_employmentRateStable = true;
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
	if( isSet_employmentRate & isSet_employmentRateZero & isSet_employmentRateStable ) {
		double val = (employmentRate - employmentRateZero) * employmentRateStable;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}