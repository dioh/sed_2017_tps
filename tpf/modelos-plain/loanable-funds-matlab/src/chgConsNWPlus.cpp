#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgConsNWPlus.h"

using namespace std;

chgConsNWPlus::chgConsNWPlus(const string &name) :
	Atomic(name),
	Interest(addInputPort("Interest")),
	InvBuy(addInputPort("InvBuy")),
	ConsW(addInputPort("ConsW")),
	ConsB(addInputPort("ConsB")),
	IntFee(addInputPort("IntFee")),
	WagesC(addInputPort("WagesC")),
	ConstantBuy(addInputPort("ConstantBuy")),
	isSet_val_Interest(false),
	isSet_val_InvBuy(false),
	isSet_val_ConsW(false),
	isSet_val_ConsB(false),
	isSet_val_IntFee(false),
	isSet_val_WagesC(false),
	isSet_val_ConstantBuy(false),
	out(addOutputPort("out"))
{
}


Model &chgConsNWPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgConsNWPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	if(msg.port() == InvBuy) {
		val_InvBuy = x;
		isSet_val_InvBuy = true;
	}
	if(msg.port() == ConsW) {
		val_ConsW = x;
		isSet_val_ConsW = true;
	}
	if(msg.port() == ConsB) {
		val_ConsB = x;
		isSet_val_ConsB = true;
	}
	if(msg.port() == IntFee) {
		val_IntFee = x;
		isSet_val_IntFee = true;
	}
	if(msg.port() == WagesC) {
		val_WagesC = x;
		isSet_val_WagesC = true;
	}
	if(msg.port() == ConstantBuy) {
		val_ConstantBuy = x;
		isSet_val_ConstantBuy = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgConsNWPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgConsNWPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Interest & isSet_val_InvBuy & isSet_val_ConsW & isSet_val_ConsB & isSet_val_IntFee & isSet_val_WagesC & isSet_val_ConstantBuy ) {
		double val = ((((val_Interest+val_InvBuy)+val_ConsW)+val_ConsB)-((val_IntFee+val_WagesC)+val_ConstantBuy));
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}