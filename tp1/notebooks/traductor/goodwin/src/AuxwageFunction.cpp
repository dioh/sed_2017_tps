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
	in_effectOfEmploymentRateInWages(addInputPort("in_effectOfEmploymentRateInWages")),
	in_constantEmploymentRate(addInputPort("in_constantEmploymentRate")),
	in_employmentRate(addInputPort("in_employmentRate")),
	isSet_effectOfEmploymentRateInWages(false),
	isSet_constantEmploymentRate(false),
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

	if(msg.port() == in_effectOfEmploymentRateInWages) {
		effectOfEmploymentRateInWages = x;
		isSet_effectOfEmploymentRateInWages = true;
	}
	if(msg.port() == in_constantEmploymentRate) {
		constantEmploymentRate = x;
		isSet_constantEmploymentRate = true;
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
	if( isSet_effectOfEmploymentRateInWages & isSet_constantEmploymentRate & isSet_employmentRate ) {
		double val = (employmentRate - constantEmploymentRate) * effectOfEmploymentRateInWages;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}