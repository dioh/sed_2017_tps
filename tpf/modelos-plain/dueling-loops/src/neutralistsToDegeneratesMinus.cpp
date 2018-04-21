#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "neutralistsToDegeneratesMinus.h"

using namespace std;

neutralistsToDegeneratesMinus::neutralistsToDegeneratesMinus(const string &name) :
	Atomic(name),
	Neutralists(addInputPort("Neutralists")),
	isSet_val_Neutralists(false),
	out(addOutputPort("out"))
{
}


Model &neutralistsToDegeneratesMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &neutralistsToDegeneratesMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Neutralists) {
		val_Neutralists = x;
		isSet_val_Neutralists = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &neutralistsToDegeneratesMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &neutralistsToDegeneratesMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Neutralists ) {
		double val = 0.4 * val_Neutralists;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}