#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalsToNeutralistsMinus.h"

using namespace std;

rationalsToNeutralistsMinus::rationalsToNeutralistsMinus(const string &name) :
	Atomic(name),
	RationalSupporters(addInputPort("RationalSupporters")),
	isSet_val_RationalSupporters(false),
	out(addOutputPort("out"))
{
}


Model &rationalsToNeutralistsMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalsToNeutralistsMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == RationalSupporters) {
		val_RationalSupporters = x;
		isSet_val_RationalSupporters = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rationalsToNeutralistsMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalsToNeutralistsMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_RationalSupporters ) {
		double val = 1 * val_RationalSupporters;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}