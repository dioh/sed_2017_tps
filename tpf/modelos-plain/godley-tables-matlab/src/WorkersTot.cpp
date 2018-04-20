#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WorkersTot.h"

using namespace std;

WorkersTot::WorkersTot(const string &name) :
	Atomic(name),
	chgWorkersPlus(addInputPort("chgWorkersPlus")),
	isSet_val_chgWorkersPlus(false),
	out(addOutputPort("out"))
{
}


Model &WorkersTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WorkersTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgWorkersPlus) {
		val_chgWorkersPlus = x;
		isSet_val_chgWorkersPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WorkersTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WorkersTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgWorkersPlus) {
		plus = plus + val_chgWorkersPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}