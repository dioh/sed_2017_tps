#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotLoansDEVS_BASIC_COUPLED_Loans.h"

using namespace std;

TotLoansDEVS_BASIC_COUPLED_Loans::TotLoansDEVS_BASIC_COUPLED_Loans(const string &name) :
	Atomic(name),
	in_plus_port_chgLoans_Loans(addInputPort("in_plus_port_chgLoans_Loans")),
	isSet_chgLoans_Loans(false),
	out_port_TotLoans(addOutputPort("out_port_TotLoans"))
	{
}


Model &TotLoansDEVS_BASIC_COUPLED_Loans::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotLoansDEVS_BASIC_COUPLED_Loans::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgLoans_Loans) {
		chgLoans_Loans = x;
		isSet_chgLoans_Loans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotLoansDEVS_BASIC_COUPLED_Loans::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotLoansDEVS_BASIC_COUPLED_Loans::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgLoans_Loans) {
		plus = plus + chgLoans_Loans;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotLoans, out_value);
		}

	return *this ;
}