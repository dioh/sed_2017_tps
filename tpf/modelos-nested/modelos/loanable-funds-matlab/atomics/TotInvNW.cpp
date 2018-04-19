#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotInvNW.h"

using namespace std;

TotInvNW::TotInvNW(const string &name) :
	Atomic(name),
	in_plus_port_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW(addInputPort("in_plus_port_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW")),
	isSet_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW(false),
	out_port_TotInvNW(addOutputPort("out_port_TotInvNW"))
	{
}


Model &TotInvNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotInvNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW) {
		chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW = x;
		isSet_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotInvNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotInvNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW) {
		plus = plus + chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotInvNW, out_value);
		}

	return *this ;
}