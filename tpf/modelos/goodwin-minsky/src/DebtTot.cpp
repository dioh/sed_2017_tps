#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "DebtTot.h"

using namespace std;

DebtTot::DebtTot(const string &name) :
	Atomic(name),
	chgDebtPlus(addInputPort("chgDebtPlus")),
	isSet_val_chgDebtPlus(false),
	out(addOutputPort("out"))
{
}


Model &DebtTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &DebtTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgDebtPlus) {
		val_chgDebtPlus = x;
		isSet_val_chgDebtPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &DebtTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &DebtTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_chgDebtPlus ) {
		plus = plus + val_chgDebtPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}