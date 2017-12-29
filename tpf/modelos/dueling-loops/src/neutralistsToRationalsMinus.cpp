#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "neutralistsToRationalsMinus.h"

using namespace std;

neutralistsToRationalsMinus::neutralistsToRationalsMinus(const string &name) :
	Atomic(name),
	Neutralists(addInputPort("Neutralists")),
	isSet_val_Neutralists(false),
	out(addOutputPort("out"))
{
}


Model &neutralistsToRationalsMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &neutralistsToRationalsMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Neutralists) {
		val_Neutralists = x;
		isSet_val_Neutralists = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &neutralistsToRationalsMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &neutralistsToRationalsMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Neutralists ) {
		double val = 0.4 * val_Neutralists;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}