#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "falseMemes.h"

using namespace std;

falseMemes::falseMemes(const string &name) :
	Atomic(name),
	degeneratesInfluence(addInputPort("degeneratesInfluence")),
	falseMemeSize(addInputPort("falseMemeSize")),
	isSet_val_degeneratesInfluence(false),
	isSet_val_falseMemeSize(false),
	out(addOutputPort("out"))
{
}


Model &falseMemes::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &falseMemes::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == degeneratesInfluence) {
		val_degeneratesInfluence = x;
		isSet_val_degeneratesInfluence = true;
	}
	if(msg.port() == falseMemeSize) {
		val_falseMemeSize = x;
		isSet_val_falseMemeSize = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &falseMemes::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &falseMemes::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_degeneratesInfluence & isSet_val_falseMemeSize ) {
		double val = val_degeneratesInfluence * val_falseMemeSize;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}