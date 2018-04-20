#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConsB.h"

using namespace std;

ConsB::ConsB(const string &name) :
	Atomic(name),
	Bank(addInputPort("Bank")),
	tauBVal(addInputPort("tauBVal")),
	isSet_val_Bank(false),
	isSet_val_tauBVal(false),
	out(addOutputPort("out"))
{
}


Model &ConsB::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConsB::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Bank) {
		val_Bank = x;
		isSet_val_Bank = true;
	}
	if(msg.port() == tauBVal) {
		val_tauBVal = x;
		isSet_val_tauBVal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConsB::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConsB::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Bank & isSet_val_tauBVal ) {
		double val = (val_Bank/val_tauBVal);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}