#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConsNWTot.h"

using namespace std;

ConsNWTot::ConsNWTot(const string &name) :
	Atomic(name),
	chgConsNWPlus(addInputPort("chgConsNWPlus")),
	isSet_val_chgConsNWPlus(false),
	out(addOutputPort("out"))
{
}


Model &ConsNWTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConsNWTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgConsNWPlus) {
		val_chgConsNWPlus = x;
		isSet_val_chgConsNWPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConsNWTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConsNWTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgConsNWPlus) {
		plus = plus + val_chgConsNWPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}