#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "degeneratesMaturationRateMinus.h"

using namespace std;

degeneratesMaturationRateMinus::degeneratesMaturationRateMinus(const string &name) :
	Atomic(name),
	Neutralists(addInputPort("Neutralists")),
	degeneratesInfectivityRate(addInputPort("degeneratesInfectivityRate")),
	isSet_val_Neutralists(false),
	isSet_val_degeneratesInfectivityRate(false),
	out(addOutputPort("out"))
{
}


Model &degeneratesMaturationRateMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &degeneratesMaturationRateMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Neutralists) {
		val_Neutralists = x;
		isSet_val_Neutralists = true;
	}
	if(msg.port() == degeneratesInfectivityRate) {
		val_degeneratesInfectivityRate = x;
		isSet_val_degeneratesInfectivityRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &degeneratesMaturationRateMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &degeneratesMaturationRateMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Neutralists & isSet_val_degeneratesInfectivityRate ) {
		double val = val_Neutralists * val_degeneratesInfectivityRate;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}