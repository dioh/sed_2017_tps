#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgBankersNWPlus.h"

using namespace std;

chgBankersNWPlus::chgBankersNWPlus(const string &name) :
	Atomic(name),
	IntFee(addInputPort("IntFee")),
	ConsB(addInputPort("ConsB")),
	isSet_val_IntFee(false),
	isSet_val_ConsB(false),
	out(addOutputPort("out"))
{
}


Model &chgBankersNWPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgBankersNWPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == IntFee) {
		val_IntFee = x;
		isSet_val_IntFee = true;
	}
	if(msg.port() == ConsB) {
		val_ConsB = x;
		isSet_val_ConsB = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgBankersNWPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgBankersNWPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_IntFee & isSet_val_ConsB ) {
		double val = (val_IntFee-val_ConsB);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}