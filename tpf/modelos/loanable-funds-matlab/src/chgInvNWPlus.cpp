#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgInvNWPlus.h"

using namespace std;

chgInvNWPlus::chgInvNWPlus(const string &name) :
	Atomic(name),
	ConstantBuy(addInputPort("ConstantBuy")),
	Interest(addInputPort("Interest")),
	WagesI(addInputPort("WagesI")),
	InvBuy(addInputPort("InvBuy")),
	isSet_val_ConstantBuy(false),
	isSet_val_Interest(false),
	isSet_val_WagesI(false),
	isSet_val_InvBuy(false),
	out(addOutputPort("out"))
{
}


Model &chgInvNWPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgInvNWPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == ConstantBuy) {
		val_ConstantBuy = x;
		isSet_val_ConstantBuy = true;
	}
	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
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


Model &chgInvNWPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgInvNWPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_ConstantBuy & isSet_val_Interest & isSet_val_WagesI & isSet_val_InvBuy ) {
		double val = (val_ConstantBuy-((val_Interest+val_WagesI)+val_InvBuy));
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}