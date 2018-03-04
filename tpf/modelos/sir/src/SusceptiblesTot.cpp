#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "SusceptiblesTot.h"

using namespace std;

SusceptiblesTot::SusceptiblesTot(const string &name) :
	Atomic(name),
	SuccumbingMinus(addInputPort("SuccumbingMinus")),
	isSet_val_SuccumbingMinus(false),
	out(addOutputPort("out"))
{
}


Model &SusceptiblesTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &SusceptiblesTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == SuccumbingMinus) {
		val_SuccumbingMinus = x;
		isSet_val_SuccumbingMinus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &SusceptiblesTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &SusceptiblesTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_SuccumbingMinus) {
		minus = minus + val_SuccumbingMinus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}