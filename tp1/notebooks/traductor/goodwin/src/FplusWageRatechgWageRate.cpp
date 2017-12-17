#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusWageRatechgWageRate.h"

using namespace std;

FplusWageRatechgWageRate::FplusWageRatechgWageRate(const string &name) :
	Atomic(name),
	in_wageFunction(addInputPort("in_wageFunction")),
	in_wageRateIntegrator(addInputPort("in_wageRateIntegrator")),
	isSet_wageFunction(false),
	isSet_wageRateIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FplusWageRatechgWageRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusWageRatechgWageRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_wageFunction) {
		wageFunction = x;
		isSet_wageFunction = true;
	}
	if(msg.port() == in_wageRateIntegrator) {
		wageRateIntegrator = x;
		isSet_wageRateIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusWageRatechgWageRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusWageRatechgWageRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_wageFunction & isSet_wageRateIntegrator ) {
		double val = wageFunction * wageRateIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}