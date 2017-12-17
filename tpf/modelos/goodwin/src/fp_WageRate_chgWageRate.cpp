#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_WageRate_chgWageRate.h"

using namespace std;

fp_WageRate_chgWageRate::fp_WageRate_chgWageRate(const string &name) :
	Atomic(name),
	in_wageFunction(addInputPort("in_wageFunction")),
	in_WageRate(addInputPort("in_WageRate")),
	isSet_wageFunction(false),
	isSet_WageRate(false),
	out(addOutputPort("out"))

{
}


Model &fp_WageRate_chgWageRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_WageRate_chgWageRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_wageFunction) {
		wageFunction = x;
		isSet_wageFunction = true;
	}
	if(msg.port() == in_WageRate) {
		WageRate = x;
		isSet_WageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_WageRate_chgWageRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_WageRate_chgWageRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_wageFunction & isSet_WageRate ) {
		double val = wageFunction * WageRate;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}