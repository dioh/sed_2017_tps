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
	BankersNW(addInputPort("BankersNW")),
	tauBC(addInputPort("tauBC")),
	isSet_val_BankersNW(false),
	isSet_val_tauBC(false),
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

	if(msg.port() == BankersNW) {
		val_BankersNW = x;
		isSet_val_BankersNW = true;
	}
	if(msg.port() == tauBC) {
		val_tauBC = x;
		isSet_val_tauBC = true;
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
	if( isSet_val_BankersNW & isSet_val_tauBC ) {
		double val = (val_BankersNW/val_tauBC);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}