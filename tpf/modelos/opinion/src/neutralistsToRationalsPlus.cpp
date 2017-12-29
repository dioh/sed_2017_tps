#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "neutralistsToRationalsPlus.h"

using namespace std;

neutralistsToRationalsPlus::neutralistsToRationalsPlus(const string &name) :
	Atomic(name),
	Neutralists(addInputPort("Neutralists")),
	isSet_val_Neutralists(false),
	out(addOutputPort("out"))
{
}


Model &neutralistsToRationalsPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &neutralistsToRationalsPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Neutralists) {
		val_Neutralists = x;
		isSet_val_Neutralists = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &neutralistsToRationalsPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &neutralistsToRationalsPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Neutralists ) {
		double val = 0.4 * val_Neutralists;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}