#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InfectedTot.h"

using namespace std;

InfectedTot::InfectedTot(const string &name) :
	Atomic(name),
	SuccumbingPlus(addInputPort("SuccumbingPlus")),
	RecoveringMinus(addInputPort("RecoveringMinus")),
	isSet_val_SuccumbingPlus(false),
	isSet_val_RecoveringMinus(false),
	out(addOutputPort("out"))
{
}


Model &InfectedTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InfectedTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == SuccumbingPlus) {
		val_SuccumbingPlus = x;
		isSet_val_SuccumbingPlus = true;
	}
	if(msg.port() == RecoveringMinus) {
		val_RecoveringMinus = x;
		isSet_val_RecoveringMinus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InfectedTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InfectedTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_SuccumbingPlus & isSet_val_RecoveringMinus) {
		plus = plus + val_SuccumbingPlus;
		minus = minus + val_RecoveringMinus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}