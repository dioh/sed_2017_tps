#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FirmsTot.h"

using namespace std;

FirmsTot::FirmsTot(const string &name) :
	Atomic(name),
	chgFirmsPlus(addInputPort("chgFirmsPlus")),
	isSet_val_chgFirmsPlus(false),
	out(addOutputPort("out"))
{
}


Model &FirmsTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FirmsTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgFirmsPlus) {
		val_chgFirmsPlus = x;
		isSet_val_chgFirmsPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FirmsTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FirmsTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgFirmsPlus) {
		plus = plus + val_chgFirmsPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}