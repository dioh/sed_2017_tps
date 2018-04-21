#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalistsMaturationRateMinus.h"

using namespace std;

rationalistsMaturationRateMinus::rationalistsMaturationRateMinus(const string &name) :
	Atomic(name),
	Neutralists(addInputPort("Neutralists")),
	rationalistsInfectivityRate(addInputPort("rationalistsInfectivityRate")),
	isSet_val_Neutralists(false),
	isSet_val_rationalistsInfectivityRate(false),
	out(addOutputPort("out"))
{
}


Model &rationalistsMaturationRateMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalistsMaturationRateMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Neutralists) {
		val_Neutralists = x;
		isSet_val_Neutralists = true;
	}
	if(msg.port() == rationalistsInfectivityRate) {
		val_rationalistsInfectivityRate = x;
		isSet_val_rationalistsInfectivityRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rationalistsMaturationRateMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalistsMaturationRateMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Neutralists & isSet_val_rationalistsInfectivityRate ) {
		double val = val_Neutralists * val_rationalistsInfectivityRate;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}