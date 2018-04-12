#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW.h"

using namespace std;

chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW::chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW(const string &name) :
	Atomic(name),
    in_port_InvBuy(addInputPort("in_port_InvBuy")),
    in_port_ConsW(addInputPort("in_port_ConsW")),
    in_port_ConstantBuy(addInputPort("in_port_ConstantBuy")),
    in_port_ConsB(addInputPort("in_port_ConsB")),
    in_port_IntFee(addInputPort("in_port_IntFee")),
    in_port_Interest(addInputPort("in_port_Interest")),
    in_port_WagesC(addInputPort("in_port_WagesC")),
    isSet_InvBuy(false),
    isSet_ConsW(false),
    isSet_ConstantBuy(false),
    isSet_ConsB(false),
    isSet_IntFee(false),
    isSet_Interest(false),
    isSet_WagesC(false),
	out_port_chgConsNW_ConsNW(addOutputPort("out_port_chgConsNW_ConsNW"))
{
}


Model &chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

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
	if(msg.port() == in_port_ConsB) {
		ConsB = x;
		isSet_ConsB = true;
	}
	if(msg.port() == in_port_IntFee) {
		IntFee = x;
		isSet_IntFee = true;
	}
	if(msg.port() == in_port_Interest) {
		Interest = x;
		isSet_Interest = true;
	}
	if(msg.port() == in_port_WagesC) {
		WagesC = x;
		isSet_WagesC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_InvBuy & isSet_ConsW & isSet_ConstantBuy & isSet_ConsB & isSet_IntFee & isSet_Interest & isSet_WagesC ) {
	    Tuple<Real> out_value { ((((Interest+InvBuy)+ConsW)+ConsB)-((IntFee+WagesC)+ConstantBuy)) };
		sendOutput(msg.time(), out_port_chgConsNW_ConsNW, out_value);
	}
	
	return *this ;
}