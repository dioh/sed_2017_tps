#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgwageRatePlus.h"

using namespace std;

chgwageRatePlus::chgwageRatePlus(const string &name) :
	Atomic(name),
	wageFunction(addInputPort("wageFunction")),
	wageRate(addInputPort("wageRate")),
	isSet_val_wageFunction(false),
	isSet_val_wageRate(false),
	out(addOutputPort("out"))
{
}


Model &chgwageRatePlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgwageRatePlus::externalFunction(const ExternalMessage &msg)
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


Model &chgwageRatePlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgwageRatePlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_wageFunction & isSet_val_wageRate ) {
		double val = (val_wageFunction*val_wageRate);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}