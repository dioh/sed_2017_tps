#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalsToNeutralistsPlus.h"

using namespace std;

rationalsToNeutralistsPlus::rationalsToNeutralistsPlus(const string &name) :
	Atomic(name),
	RationalSupporters(addInputPort("RationalSupporters")),
	isSet_val_RationalSupporters(false),
	out(addOutputPort("out"))
{
}


Model &rationalsToNeutralistsPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalsToNeutralistsPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == RationalSupporters) {
		val_RationalSupporters = x;
		isSet_val_RationalSupporters = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rationalsToNeutralistsPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalsToNeutralistsPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_RationalSupporters ) {
		double val = 1 * val_RationalSupporters;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}