#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW.h"

using namespace std;

chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW::chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW(const string &name) :
	Atomic(name),
    in_port_WagesI(addInputPort("in_port_WagesI")),
    in_port_InvBuy(addInputPort("in_port_InvBuy")),
    in_port_Interest(addInputPort("in_port_Interest")),
    in_port_ConstantBuy(addInputPort("in_port_ConstantBuy")),
    isSet_WagesI(false),
    isSet_InvBuy(false),
    isSet_Interest(false),
    isSet_ConstantBuy(false),
	out_port_chgInvNW_InvNW(addOutputPort("out_port_chgInvNW_InvNW"))
{
}


Model &chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_WagesI) {
		WagesI = x;
		isSet_WagesI = true;
	}
	if(msg.port() == in_port_InvBuy) {
		InvBuy = x;
		isSet_InvBuy = true;
	}
	if(msg.port() == in_port_Interest) {
		Interest = x;
		isSet_Interest = true;
	}
	if(msg.port() == in_port_ConstantBuy) {
		ConstantBuy = x;
		isSet_ConstantBuy = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_WagesI & isSet_InvBuy & isSet_Interest & isSet_ConstantBuy ) {
	    Tuple<Real> out_value { (ConstantBuy-((Interest+WagesI)+InvBuy)) };
		sendOutput(msg.time(), out_port_chgInvNW_InvNW, out_value);
	}
	
	return *this ;
}