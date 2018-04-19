#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotLoans.h"

using namespace std;

TotLoans::TotLoans(const string &name) :
	Atomic(name),
	in_plus_port_chgLoans_LoansDEVS_BASIC_COUPLED_Loans(addInputPort("in_plus_port_chgLoans_LoansDEVS_BASIC_COUPLED_Loans")),
	isSet_chgLoans_LoansDEVS_BASIC_COUPLED_Loans(false),
	out_port_TotLoans(addOutputPort("out_port_TotLoans"))
	{
}


Model &TotLoans::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotLoans::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgLoans_LoansDEVS_BASIC_COUPLED_Loans) {
		chgLoans_LoansDEVS_BASIC_COUPLED_Loans = x;
		isSet_chgLoans_LoansDEVS_BASIC_COUPLED_Loans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotLoans::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotLoans::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgLoans_LoansDEVS_BASIC_COUPLED_Loans) {
		plus = plus + chgLoans_LoansDEVS_BASIC_COUPLED_Loans;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotLoans, out_value);
		}

	return *this ;
}