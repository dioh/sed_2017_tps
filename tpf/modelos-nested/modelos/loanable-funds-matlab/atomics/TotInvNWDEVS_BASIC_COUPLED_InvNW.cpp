#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotInvNWDEVS_BASIC_COUPLED_InvNW.h"

using namespace std;

TotInvNWDEVS_BASIC_COUPLED_InvNW::TotInvNWDEVS_BASIC_COUPLED_InvNW(const string &name) :
	Atomic(name),
	in_plus_port_chgInvNW_InvNW(addInputPort("in_plus_port_chgInvNW_InvNW")),
	isSet_chgInvNW_InvNW(false),
	out_port_TotInvNW(addOutputPort("out_port_TotInvNW"))
	{
}


Model &TotInvNWDEVS_BASIC_COUPLED_InvNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotInvNWDEVS_BASIC_COUPLED_InvNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgInvNW_InvNW) {
		chgInvNW_InvNW = x;
		isSet_chgInvNW_InvNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotInvNWDEVS_BASIC_COUPLED_InvNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotInvNWDEVS_BASIC_COUPLED_InvNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgInvNW_InvNW) {
		plus = plus + chgInvNW_InvNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotInvNW, out_value);
		}

	return *this ;
}