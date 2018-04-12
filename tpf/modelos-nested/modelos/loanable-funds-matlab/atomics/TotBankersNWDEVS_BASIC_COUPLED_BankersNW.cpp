#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotBankersNWDEVS_BASIC_COUPLED_BankersNW.h"

using namespace std;

TotBankersNWDEVS_BASIC_COUPLED_BankersNW::TotBankersNWDEVS_BASIC_COUPLED_BankersNW(const string &name) :
	Atomic(name),
	in_plus_port_chgBankersNW_BankersNW(addInputPort("in_plus_port_chgBankersNW_BankersNW")),
	isSet_chgBankersNW_BankersNW(false),
	out_port_TotBankersNW(addOutputPort("out_port_TotBankersNW"))
	{
}


Model &TotBankersNWDEVS_BASIC_COUPLED_BankersNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotBankersNWDEVS_BASIC_COUPLED_BankersNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgBankersNW_BankersNW) {
		chgBankersNW_BankersNW = x;
		isSet_chgBankersNW_BankersNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotBankersNWDEVS_BASIC_COUPLED_BankersNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotBankersNWDEVS_BASIC_COUPLED_BankersNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgBankersNW_BankersNW) {
		plus = plus + chgBankersNW_BankersNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotBankersNW, out_value);
		}

	return *this ;
}