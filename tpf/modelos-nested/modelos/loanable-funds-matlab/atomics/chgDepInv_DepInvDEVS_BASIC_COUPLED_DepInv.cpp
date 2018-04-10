#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv.h"

using namespace std;

chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv::chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv(const string &name) :
	Atomic(name),
    in_port_Repay(addInputPort("in_port_Repay")),
    in_port_Interest(addInputPort("in_port_Interest")),
    in_port_WagesI(addInputPort("in_port_WagesI")),
    in_port_Lend(addInputPort("in_port_Lend")),
    in_port_InvBuy(addInputPort("in_port_InvBuy")),
    in_port_ConstantBuy(addInputPort("in_port_ConstantBuy")),
    isSet_Repay(false),
    isSet_Interest(false),
    isSet_WagesI(false),
    isSet_Lend(false),
    isSet_InvBuy(false),
    isSet_ConstantBuy(false),
	out_port_chgDepInv_DepInv(addOutputPort("out_port_chgDepInv_DepInv"))
{
}


Model &chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Repay) {
		Repay = x;
		isSet_Repay = true;
	}
	if(msg.port() == in_port_Interest) {
		Interest = x;
		isSet_Interest = true;
	}
	if(msg.port() == in_port_WagesI) {
		WagesI = x;
		isSet_WagesI = true;
	}
	if(msg.port() == in_port_Lend) {
		Lend = x;
		isSet_Lend = true;
	}
	if(msg.port() == in_port_InvBuy) {
		InvBuy = x;
		isSet_InvBuy = true;
	}
	if(msg.port() == in_port_ConstantBuy) {
		ConstantBuy = x;
		isSet_ConstantBuy = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Repay & isSet_Interest & isSet_WagesI & isSet_Lend & isSet_InvBuy & isSet_ConstantBuy ) {
	    Tuple<Real> out_value { ((Lend+ConstantBuy)-(((Interest+Repay)+WagesI)+InvBuy)) };
		sendOutput(msg.time(), out_port_chgDepInv_DepInv, out_value);
	}
	
	return *this ;
}