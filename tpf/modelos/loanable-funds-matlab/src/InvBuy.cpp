#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvBuy.h"

using namespace std;

InvBuy::InvBuy(const string &name) :
	Atomic(name),
	PiIG(addInputPort("PiIG")),
	IPCValue(addInputPort("IPCValue")),
	isSet_val_PiIG(false),
	isSet_val_IPCValue(false),
	out(addOutputPort("out"))
{
}


Model &InvBuy::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvBuy::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == PiIG) {
		val_PiIG = x;
		isSet_val_PiIG = true;
	}
	if(msg.port() == IPCValue) {
		val_IPCValue = x;
		isSet_val_IPCValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvBuy::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvBuy::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_PiIG & isSet_val_IPCValue ) {
		double val = (val_PiIG*val_IPCValue);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}