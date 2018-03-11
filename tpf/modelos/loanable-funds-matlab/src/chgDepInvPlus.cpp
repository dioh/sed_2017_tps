#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgDepInvPlus.h"

using namespace std;

chgDepInvPlus::chgDepInvPlus(const string &name) :
	Atomic(name),
	Lend(addInputPort("Lend")),
	ConstantBuy(addInputPort("ConstantBuy")),
	Interest(addInputPort("Interest")),
	Repay(addInputPort("Repay")),
	WagesI(addInputPort("WagesI")),
	InvBuy(addInputPort("InvBuy")),
	isSet_val_Lend(false),
	isSet_val_ConstantBuy(false),
	isSet_val_Interest(false),
	isSet_val_Repay(false),
	isSet_val_WagesI(false),
	isSet_val_InvBuy(false),
	out(addOutputPort("out"))
{
}


Model &chgDepInvPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgDepInvPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Lend) {
		val_Lend = x;
		isSet_val_Lend = true;
	}
	if(msg.port() == ConstantBuy) {
		val_ConstantBuy = x;
		isSet_val_ConstantBuy = true;
	}
	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	if(msg.port() == Repay) {
		val_Repay = x;
		isSet_val_Repay = true;
	}
	if(msg.port() == WagesI) {
		val_WagesI = x;
		isSet_val_WagesI = true;
	}
	if(msg.port() == InvBuy) {
		val_InvBuy = x;
		isSet_val_InvBuy = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgDepInvPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgDepInvPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Lend & isSet_val_ConstantBuy & isSet_val_Interest & isSet_val_Repay & isSet_val_WagesI & isSet_val_InvBuy ) {
		double val = ((val_Lend+val_ConstantBuy)-(((val_Interest+val_Repay)+val_WagesI)+val_InvBuy));
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}