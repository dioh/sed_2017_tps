#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalistsInfluence.h"

using namespace std;

rationalistsInfluence::rationalistsInfluence(const string &name) :
	Atomic(name),
	RationalSupporters(addInputPort("RationalSupporters")),
	influencePerRationalist(addInputPort("influencePerRationalist")),
	isSet_val_RationalSupporters(false),
	isSet_val_influencePerRationalist(false),
	out(addOutputPort("out"))
{
}


Model &rationalistsInfluence::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalistsInfluence::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == RationalSupporters) {
		val_RationalSupporters = x;
		isSet_val_RationalSupporters = true;
	}
	if(msg.port() == influencePerRationalist) {
		val_influencePerRationalist = x;
		isSet_val_influencePerRationalist = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rationalistsInfluence::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalistsInfluence::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_RationalSupporters & isSet_val_influencePerRationalist ) {
		double val = val_RationalSupporters * val_influencePerRationalist;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}