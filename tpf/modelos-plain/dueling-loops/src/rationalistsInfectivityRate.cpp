#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rationalistsInfectivityRate.h"

using namespace std;

rationalistsInfectivityRate::rationalistsInfectivityRate(const string &name) :
	Atomic(name),
	trueMemes(addInputPort("trueMemes")),
	memeticInfectivity(addInputPort("memeticInfectivity")),
	incubationTime(addInputPort("incubationTime")),
	isSet_val_trueMemes(false),
	isSet_val_memeticInfectivity(false),
	isSet_val_incubationTime(false),
	out(addOutputPort("out"))
{
}


Model &rationalistsInfectivityRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rationalistsInfectivityRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == trueMemes) {
		val_trueMemes = x;
		isSet_val_trueMemes = true;
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


Model &rationalistsInfectivityRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rationalistsInfectivityRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_trueMemes & isSet_val_memeticInfectivity & isSet_val_incubationTime ) {
		double val = (val_trueMemes * val_memeticInfectivity) / val_incubationTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}