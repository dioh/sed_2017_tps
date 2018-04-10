#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons.h"

using namespace std;

chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons::chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons(const string &name) :
	Atomic(name),
    in_port_Lend(addInputPort("in_port_Lend")),
    in_port_InvBuy(addInputPort("in_port_InvBuy")),
    in_port_ConsW(addInputPort("in_port_ConsW")),
    in_port_ConstantBuy(addInputPort("in_port_ConstantBuy")),
    in_port_WagesC(addInputPort("in_port_WagesC")),
    in_port_Repay(addInputPort("in_port_Repay")),
    in_port_Interest(addInputPort("in_port_Interest")),
    in_port_ConsB(addInputPort("in_port_ConsB")),
    in_port_IntFee(addInputPort("in_port_IntFee")),
    isSet_Lend(false),
    isSet_InvBuy(false),
    isSet_ConsW(false),
    isSet_ConstantBuy(false),
    isSet_WagesC(false),
    isSet_Repay(false),
    isSet_Interest(false),
    isSet_ConsB(false),
    isSet_IntFee(false),
	out_port_chgDepCons_DepCons(addOutputPort("out_port_chgDepCons_DepCons"))
{
}


Model &chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Lend) {
		Lend = x;
		isSet_Lend = true;
	}
	if(msg.port() == in_port_InvBuy) {
		InvBuy = x;
		isSet_InvBuy = true;
	}
	if(msg.port() == in_port_ConsW) {
		ConsW = x;
		isSet_ConsW = true;
	}
	if(msg.port() == in_port_ConstantBuy) {
		ConstantBuy = x;
		isSet_ConstantBuy = true;
	}
	if(msg.port() == in_port_WagesC) {
		WagesC = x;
		isSet_WagesC = true;
	}
	if(msg.port() == in_port_Repay) {
		Repay = x;
		isSet_Repay = true;
	}
	if(msg.port() == in_port_Interest) {
		Interest = x;
		isSet_Interest = true;
	}
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


Model &chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Lend & isSet_InvBuy & isSet_ConsW & isSet_ConstantBuy & isSet_WagesC & isSet_Repay & isSet_Interest & isSet_ConsB & isSet_IntFee ) {
	    Tuple<Real> out_value { (((((Interest+Repay)+InvBuy)+ConsW)+ConsB)-(((Lend+IntFee)+WagesC)+ConstantBuy)) };
		sendOutput(msg.time(), out_port_chgDepCons_DepCons, out_value);
	}
	
	return *this ;
}