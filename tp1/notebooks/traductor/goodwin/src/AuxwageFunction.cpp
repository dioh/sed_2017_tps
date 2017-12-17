#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxwageFunction.h"

using namespace std;

AuxwageFunction::AuxwageFunction(const string &name) :
	Atomic(name),
	in_employmentRateZero(addInputPort("in_employmentRateZero")),
	in_employmentRateStable(addInputPort("in_employmentRateStable")),
	in_employmentRate(addInputPort("in_employmentRate")),
	isSet_employmentRateZero(false),
	isSet_employmentRateStable(false),
	isSet_employmentRate(false),
	out(addOutputPort("out"))
{
}


Model &AuxwageFunction::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxwageFunction::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_employmentRateZero) {
		employmentRateZero = x;
		isSet_employmentRateZero = true;
	}
	if(msg.port() == in_employmentRateStable) {
		employmentRateStable = x;
		isSet_employmentRateStable = true;
	}
	if(msg.port() == in_employmentRate) {
		employmentRate = x;
		isSet_employmentRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxwageFunction::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxwageFunction::outputFunction(const CollectMessage &msg)
{
	if( isSet_employmentRateZero & isSet_employmentRateStable & isSet_employmentRate ) {
		double val = (employmentRate - employmentRateZero) * employmentRateStable;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}