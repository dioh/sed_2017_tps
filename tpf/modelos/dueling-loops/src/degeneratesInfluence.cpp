#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "degeneratesInfluence.h"

using namespace std;

degeneratesInfluence::degeneratesInfluence(const string &name) :
	Atomic(name),
	Degenerates(addInputPort("Degenerates")),
	influencePerDegenerate(addInputPort("influencePerDegenerate")),
	isSet_val_Degenerates(false),
	isSet_val_influencePerDegenerate(false),
	out(addOutputPort("out"))
{
}


Model &degeneratesInfluence::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &degeneratesInfluence::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Degenerates) {
		val_Degenerates = x;
		isSet_val_Degenerates = true;
	}
	if(msg.port() == influencePerDegenerate) {
		val_influencePerDegenerate = x;
		isSet_val_influencePerDegenerate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &degeneratesInfluence::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &degeneratesInfluence::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Degenerates & isSet_val_influencePerDegenerate ) {
		double val = val_Degenerates * val_influencePerDegenerate;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}