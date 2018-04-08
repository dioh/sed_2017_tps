#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "DepConsTot.h"

using namespace std;

DepConsTot::DepConsTot(const string &name) :
	Atomic(name),
	chgDepConsPlus(addInputPort("chgDepConsPlus")),
	isSet_val_chgDepConsPlus(false),
	out(addOutputPort("out"))
{
}


Model &DepConsTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &DepConsTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgDepConsPlus) {
		val_chgDepConsPlus = x;
		isSet_val_chgDepConsPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &DepConsTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &DepConsTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgDepConsPlus) {
		plus = plus + val_chgDepConsPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}