#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "degeneratesInfectivityRate.h"

using namespace std;

degeneratesInfectivityRate::degeneratesInfectivityRate(const string &name) :
	Atomic(name),
	falseMemes(addInputPort("falseMemes")),
	memeticInfectivity(addInputPort("memeticInfectivity")),
	incubationTime(addInputPort("incubationTime")),
	isSet_val_falseMemes(false),
	isSet_val_memeticInfectivity(false),
	isSet_val_incubationTime(false),
	out(addOutputPort("out"))
{
}


Model &degeneratesInfectivityRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &degeneratesInfectivityRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == falseMemes) {
		val_falseMemes = x;
		isSet_val_falseMemes = true;
	}
	if(msg.port() == memeticInfectivity) {
		val_memeticInfectivity = x;
		isSet_val_memeticInfectivity = true;
	}
	if(msg.port() == incubationTime) {
		val_incubationTime = x;
		isSet_val_incubationTime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &degeneratesInfectivityRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &degeneratesInfectivityRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_falseMemes & isSet_val_memeticInfectivity & isSet_val_incubationTime ) {
		double val = (val_falseMemes * val_memeticInfectivity) / val_incubationTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}