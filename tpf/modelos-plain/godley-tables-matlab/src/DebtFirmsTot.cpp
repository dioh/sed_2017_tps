#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "DebtFirmsTot.h"

using namespace std;

DebtFirmsTot::DebtFirmsTot(const string &name) :
	Atomic(name),
	chgDebtFirmsPlus(addInputPort("chgDebtFirmsPlus")),
	isSet_val_chgDebtFirmsPlus(false),
	out(addOutputPort("out"))
{
}


Model &DebtFirmsTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &DebtFirmsTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgDebtFirmsPlus) {
		val_chgDebtFirmsPlus = x;
		isSet_val_chgDebtFirmsPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &DebtFirmsTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &DebtFirmsTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgDebtFirmsPlus) {
		plus = plus + val_chgDebtFirmsPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}