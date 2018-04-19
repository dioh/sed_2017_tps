#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotBankersNW.h"

using namespace std;

TotBankersNW::TotBankersNW(const string &name) :
	Atomic(name),
	in_plus_port_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW(addInputPort("in_plus_port_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW")),
	isSet_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW(false),
	out_port_TotBankersNW(addOutputPort("out_port_TotBankersNW"))
	{
}


Model &TotBankersNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotBankersNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW) {
		chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW = x;
		isSet_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotBankersNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotBankersNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW) {
		plus = plus + chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotBankersNW, out_value);
		}

	return *this ;
}