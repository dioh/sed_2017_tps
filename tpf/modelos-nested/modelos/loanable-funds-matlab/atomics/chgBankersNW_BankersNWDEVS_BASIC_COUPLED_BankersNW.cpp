#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW.h"

using namespace std;

chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW::chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW(const string &name) :
	Atomic(name),
    in_port_ConsB(addInputPort("in_port_ConsB")),
    in_port_IntFee(addInputPort("in_port_IntFee")),
    isSet_ConsB(false),
    isSet_IntFee(false),
	out_port_chgBankersNW_BankersNW(addOutputPort("out_port_chgBankersNW_BankersNW"))
{
}


Model &chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_ConsB) {
		ConsB = x;
		isSet_ConsB = true;
	}
	if(msg.port() == in_port_IntFee) {
		IntFee = x;
		isSet_IntFee = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_ConsB & isSet_IntFee ) {
	    Tuple<Real> out_value { (IntFee-ConsB) };
		sendOutput(msg.time(), out_port_chgBankersNW_BankersNW, out_value);
	}
	
	return *this ;
}