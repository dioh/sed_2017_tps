#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "BankTot.h"

using namespace std;

BankTot::BankTot(const string &name) :
	Atomic(name),
	chgBankPlus(addInputPort("chgBankPlus")),
	isSet_val_chgBankPlus(false),
	out(addOutputPort("out"))
{
}


Model &BankTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &BankTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgBankPlus) {
		val_chgBankPlus = x;
		isSet_val_chgBankPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &BankTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &BankTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgBankPlus) {
		plus = plus + val_chgBankPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}