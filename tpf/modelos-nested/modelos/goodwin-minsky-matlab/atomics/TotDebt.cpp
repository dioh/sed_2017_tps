#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotDebt.h"

using namespace std;

TotDebt::TotDebt(const string &name) :
	Atomic(name),
	in_plus_port_chgDebt_DebtDEVS_BASIC_COUPLED_Debt(addInputPort("in_plus_port_chgDebt_DebtDEVS_BASIC_COUPLED_Debt")),
	isSet_chgDebt_DebtDEVS_BASIC_COUPLED_Debt(false),
	out_port_TotDebt(addOutputPort("out_port_TotDebt"))
	{
}


Model &TotDebt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotDebt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgDebt_DebtDEVS_BASIC_COUPLED_Debt) {
		chgDebt_DebtDEVS_BASIC_COUPLED_Debt = x;
		isSet_chgDebt_DebtDEVS_BASIC_COUPLED_Debt = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotDebt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotDebt::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgDebt_DebtDEVS_BASIC_COUPLED_Debt) {
		plus = plus + chgDebt_DebtDEVS_BASIC_COUPLED_Debt;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotDebt, out_value);
		}

	return *this ;
}