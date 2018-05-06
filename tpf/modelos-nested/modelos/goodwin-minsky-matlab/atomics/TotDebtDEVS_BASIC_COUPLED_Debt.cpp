#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotDebtDEVS_BASIC_COUPLED_Debt.h"

using namespace std;

TotDebtDEVS_BASIC_COUPLED_Debt::TotDebtDEVS_BASIC_COUPLED_Debt(const string &name) :
	Atomic(name),
	in_plus_port_chgDebt_Debt(addInputPort("in_plus_port_chgDebt_Debt")),
	isSet_chgDebt_Debt(false),
	out_port_TotDebt(addOutputPort("out_port_TotDebt"))
	{
}


Model &TotDebtDEVS_BASIC_COUPLED_Debt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotDebtDEVS_BASIC_COUPLED_Debt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgDebt_Debt) {
		chgDebt_Debt = x;
		isSet_chgDebt_Debt = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotDebtDEVS_BASIC_COUPLED_Debt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotDebtDEVS_BASIC_COUPLED_Debt::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_chgDebt_Debt) { plus = plus + chgDebt_Debt; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotDebt, out_value);
	return *this ;
}