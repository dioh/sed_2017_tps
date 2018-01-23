#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgwageRateMinus.h"

using namespace std;

chgwageRateMinus::chgwageRateMinus(const string &name) :
	Atomic(name),
	wageFunction(addInputPort("wageFunction")),
	wageRate(addInputPort("wageRate")),
	isSet_val_wageFunction(false),
	isSet_val_wageRate(false),
	out(addOutputPort("out"))
{
}


Model &chgwageRateMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgwageRateMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == wageFunction) {
		val_wageFunction = x;
		isSet_val_wageFunction = true;
	}
	if(msg.port() == wageRate) {
		val_wageRate = x;
		isSet_val_wageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgwageRateMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgwageRateMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_wageFunction & isSet_val_wageRate ) {
		double val = (val_wageFunction*val_wageRate);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}