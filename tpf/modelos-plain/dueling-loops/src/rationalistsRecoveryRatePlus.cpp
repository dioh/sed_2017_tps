#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalistsRecoveryRatePlus.h"

using namespace std;

rationalistsRecoveryRatePlus::rationalistsRecoveryRatePlus(const string &name) :
	Atomic(name),
	RationalSupporters(addInputPort("RationalSupporters")),
	infectionLifetime(addInputPort("infectionLifetime")),
	isSet_val_RationalSupporters(false),
	isSet_val_infectionLifetime(false),
	out(addOutputPort("out"))
{
}


Model &rationalistsRecoveryRatePlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalistsRecoveryRatePlus::externalFunction(const ExternalMessage &msg)
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


Model &rationalistsRecoveryRatePlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalistsRecoveryRatePlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_RationalSupporters & isSet_val_infectionLifetime ) {
		double val = val_RationalSupporters / val_infectionLifetime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}