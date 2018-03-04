#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgWageRatePlus.h"

using namespace std;

chgWageRatePlus::chgWageRatePlus(const string &name) :
	Atomic(name),
	wageFunction(addInputPort("wageFunction")),
	WageRate(addInputPort("WageRate")),
	isSet_val_wageFunction(false),
	isSet_val_WageRate(false),
	out(addOutputPort("out"))
{
}


Model &chgWageRatePlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgWageRatePlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == wageFunction) {
		val_wageFunction = x;
		isSet_val_wageFunction = true;
	}
	if(msg.port() == WageRate) {
		val_WageRate = x;
		isSet_val_WageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgWageRatePlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgWageRatePlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_wageFunction & isSet_val_WageRate ) {
		double val = val_wageFunction * val_WageRate;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}