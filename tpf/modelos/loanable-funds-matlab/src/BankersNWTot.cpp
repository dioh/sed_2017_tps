#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "BankersNWTot.h"

using namespace std;

BankersNWTot::BankersNWTot(const string &name) :
	Atomic(name),
	chgBankersNWPlus(addInputPort("chgBankersNWPlus")),
	isSet_val_chgBankersNWPlus(false),
	out(addOutputPort("out"))
{
}


Model &BankersNWTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &BankersNWTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgBankersNWPlus) {
		val_chgBankersNWPlus = x;
		isSet_val_chgBankersNWPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &BankersNWTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &BankersNWTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgBankersNWPlus) {
		plus = plus + val_chgBankersNWPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}