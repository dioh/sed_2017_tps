#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WageRateTot.h"

using namespace std;

WageRateTot::WageRateTot(const string &name) :
	Atomic(name),
	chgWageRatePlus(addInputPort("chgWageRatePlus")),
	isSet_val_chgWageRatePlus(false),
	out(addOutputPort("out"))
{
}


Model &WageRateTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WageRateTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgWageRatePlus) {
		val_chgWageRatePlus = x;
		isSet_val_chgWageRatePlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WageRateTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WageRateTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_chgWageRatePlus ) {
		plus = plus + val_chgWageRatePlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}