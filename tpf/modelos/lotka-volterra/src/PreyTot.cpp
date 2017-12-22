#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PreyTot.h"

using namespace std;

PreyTot::PreyTot(const string &name) :
	Atomic(name),
	PlusPreyPlus(addInputPort("PlusPreyPlus")),
	MinusPreyMinus(addInputPort("MinusPreyMinus")),
	isSet_val_PlusPreyPlus(false),
	isSet_val_MinusPreyMinus(false),
	out(addOutputPort("out"))
{
}


Model &PreyTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PreyTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == PlusPreyPlus) {
		val_PlusPreyPlus = x;
		isSet_val_PlusPreyPlus = true;
	}
	if(msg.port() == MinusPreyMinus) {
		val_MinusPreyMinus = x;
		isSet_val_MinusPreyMinus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PreyTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PreyTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_PlusPreyPlus & isSet_val_MinusPreyMinus) {
		plus = plus + val_PlusPreyPlus;
		minus = minus + val_MinusPreyMinus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}