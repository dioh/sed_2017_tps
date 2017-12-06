#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotwageRateIntegrator.h"

using namespace std;

FtotwageRateIntegrator::FtotwageRateIntegrator(const string &name) :
	inPlus_chgWageRate(addInputPort("inPlus_chgWageRate")),
	out(addOutputPort("out")),
	val_inPlus_chgWageRate(0),
	isSet_val_inPlus_chgWageRate(false),
	Atomic(name)
{
}


Model &FtotwageRateIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotwageRateIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgWageRate) {
		val_inPlus_chgWageRate = x;
		isSet_val_inPlus_chgWageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotwageRateIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotwageRateIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgWageRate ) {
		plus = plus + val_inPlus_chgWageRate;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}