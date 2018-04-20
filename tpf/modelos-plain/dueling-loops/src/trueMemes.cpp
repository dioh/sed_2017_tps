#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "trueMemes.h"

using namespace std;

trueMemes::trueMemes(const string &name) :
	Atomic(name),
	rationalistsInfluence(addInputPort("rationalistsInfluence")),
	constantTrueMemeSize(addInputPort("constantTrueMemeSize")),
	isSet_val_rationalistsInfluence(false),
	isSet_val_constantTrueMemeSize(false),
	out(addOutputPort("out"))
{
}


Model &trueMemes::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &trueMemes::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == rationalistsInfluence) {
		val_rationalistsInfluence = x;
		isSet_val_rationalistsInfluence = true;
	}
	if(msg.port() == constantTrueMemeSize) {
		val_constantTrueMemeSize = x;
		isSet_val_constantTrueMemeSize = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &trueMemes::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &trueMemes::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_rationalistsInfluence & isSet_val_constantTrueMemeSize ) {
		double val = val_rationalistsInfluence * val_constantTrueMemeSize;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}