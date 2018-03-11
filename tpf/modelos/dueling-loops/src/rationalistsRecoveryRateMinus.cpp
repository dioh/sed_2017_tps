#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalistsRecoveryRateMinus.h"

using namespace std;

rationalistsRecoveryRateMinus::rationalistsRecoveryRateMinus(const string &name) :
	Atomic(name),
	RationalSupporters(addInputPort("RationalSupporters")),
	infectionLifetime(addInputPort("infectionLifetime")),
	isSet_val_RationalSupporters(false),
	isSet_val_infectionLifetime(false),
	out(addOutputPort("out"))
{
}


Model &rationalistsRecoveryRateMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalistsRecoveryRateMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == RationalSupporters) {
		val_RationalSupporters = x;
		isSet_val_RationalSupporters = true;
	}
	if(msg.port() == infectionLifetime) {
		val_infectionLifetime = x;
		isSet_val_infectionLifetime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rationalistsRecoveryRateMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalistsRecoveryRateMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_RationalSupporters & isSet_val_infectionLifetime ) {
		double val = val_RationalSupporters / val_infectionLifetime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}