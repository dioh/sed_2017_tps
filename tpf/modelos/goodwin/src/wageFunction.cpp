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
	employmentRate(addInputPort("employmentRate")),
	constantEmploymentRate(addInputPort("constantEmploymentRate")),
	isSet_val_employmentRate(false),
	isSet_val_constantEmploymentRate(false),
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

	if(msg.port() == employmentRate) {
		val_employmentRate = x;
		isSet_val_employmentRate = true;
	}
	if(msg.port() == constantEmploymentRate) {
		val_constantEmploymentRate = x;
		isSet_val_constantEmploymentRate = true;
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
	if( isSet_val_employmentRate & isSet_val_constantEmploymentRate ) {
		double val = (val_employmentRate - val_constantEmploymentRate) * 10;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}