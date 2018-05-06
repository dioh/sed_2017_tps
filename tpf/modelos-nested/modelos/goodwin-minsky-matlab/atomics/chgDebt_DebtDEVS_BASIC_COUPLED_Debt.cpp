#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgDebt_DebtDEVS_BASIC_COUPLED_Debt.h"

using namespace std;

chgDebt_DebtDEVS_BASIC_COUPLED_Debt::chgDebt_DebtDEVS_BASIC_COUPLED_Debt(const string &name) :
	Atomic(name),
    in_port_InvestmentGross(addInputPort("in_port_InvestmentGross")),
    isSet_InvestmentGross(false),
	out_port_chgDebt_Debt(addOutputPort("out_port_chgDebt_Debt"))
{
}


Model &chgDebt_DebtDEVS_BASIC_COUPLED_Debt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgDebt_DebtDEVS_BASIC_COUPLED_Debt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_InvestmentGross) {
		InvestmentGross = x;
		isSet_InvestmentGross = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgDebt_DebtDEVS_BASIC_COUPLED_Debt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgDebt_DebtDEVS_BASIC_COUPLED_Debt::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_InvestmentGross ) {
	    Tuple<Real> out_value { InvestmentGross };
		sendOutput(msg.time(), out_port_chgDebt_Debt, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_chgDebt_Debt, out_value);
	}
	
	return *this ;
}