#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WorkersNWTot.h"

using namespace std;

WorkersNWTot::WorkersNWTot(const string &name) :
	Atomic(name),
	chgWorkersNWPlus(addInputPort("chgWorkersNWPlus")),
	isSet_val_chgWorkersNWPlus(false),
	out(addOutputPort("out"))
{
}


Model &WorkersNWTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WorkersNWTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgWorkersNWPlus) {
		val_chgWorkersNWPlus = x;
		isSet_val_chgWorkersNWPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WorkersNWTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WorkersNWTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgWorkersNWPlus) {
		plus = plus + val_chgWorkersNWPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}