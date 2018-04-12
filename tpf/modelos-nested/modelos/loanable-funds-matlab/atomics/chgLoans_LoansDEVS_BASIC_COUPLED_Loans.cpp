#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgLoans_LoansDEVS_BASIC_COUPLED_Loans.h"

using namespace std;

chgLoans_LoansDEVS_BASIC_COUPLED_Loans::chgLoans_LoansDEVS_BASIC_COUPLED_Loans(const string &name) :
	Atomic(name),
    in_port_Repay(addInputPort("in_port_Repay")),
    in_port_Lend(addInputPort("in_port_Lend")),
    isSet_Repay(false),
    isSet_Lend(false),
	out_port_chgLoans_Loans(addOutputPort("out_port_chgLoans_Loans"))
{
}


Model &chgLoans_LoansDEVS_BASIC_COUPLED_Loans::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgLoans_LoansDEVS_BASIC_COUPLED_Loans::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Repay) {
		Repay = x;
		isSet_Repay = true;
	}
	if(msg.port() == in_port_Lend) {
		Lend = x;
		isSet_Lend = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgLoans_LoansDEVS_BASIC_COUPLED_Loans::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgLoans_LoansDEVS_BASIC_COUPLED_Loans::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Repay & isSet_Lend ) {
	    Tuple<Real> out_value { (Lend-Repay) };
		sendOutput(msg.time(), out_port_chgLoans_Loans, out_value);
	}
	
	return *this ;
}