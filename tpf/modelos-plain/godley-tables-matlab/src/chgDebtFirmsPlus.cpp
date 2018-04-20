#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgDebtFirmsPlus.h"

using namespace std;

chgDebtFirmsPlus::chgDebtFirmsPlus(const string &name) :
	Atomic(name),
	LendF(addInputPort("LendF")),
	RepayF(addInputPort("RepayF")),
	isSet_val_LendF(false),
	isSet_val_RepayF(false),
	out(addOutputPort("out"))
{
}


Model &chgDebtFirmsPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgDebtFirmsPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == LendF) {
		val_LendF = x;
		isSet_val_LendF = true;
	}
	if(msg.port() == RepayF) {
		val_RepayF = x;
		isSet_val_RepayF = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgDebtFirmsPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgDebtFirmsPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_LendF & isSet_val_RepayF ) {
		double val = (val_LendF-val_RepayF);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}