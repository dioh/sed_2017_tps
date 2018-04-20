#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "RecoveredTot.h"

using namespace std;

RecoveredTot::RecoveredTot(const string &name) :
	Atomic(name),
	RecoveringPlus(addInputPort("RecoveringPlus")),
	isSet_val_RecoveringPlus(false),
	out(addOutputPort("out"))
{
}


Model &RecoveredTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &RecoveredTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == RecoveringPlus) {
		val_RecoveringPlus = x;
		isSet_val_RecoveringPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &RecoveredTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &RecoveredTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_RecoveringPlus) {
		plus = plus + val_RecoveringPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}