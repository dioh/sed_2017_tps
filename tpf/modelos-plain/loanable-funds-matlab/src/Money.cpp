#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Money.h"

using namespace std;

Money::Money(const string &name) :
	Atomic(name),
	DepCons(addInputPort("DepCons")),
	DepInv(addInputPort("DepInv")),
	Workers(addInputPort("Workers")),
	BankersNW(addInputPort("BankersNW")),
	isSet_val_DepCons(false),
	isSet_val_DepInv(false),
	isSet_val_Workers(false),
	isSet_val_BankersNW(false),
	out(addOutputPort("out"))
{
}


Model &Money::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Money::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == DepCons) {
		val_DepCons = x;
		isSet_val_DepCons = true;
	}
	if(msg.port() == DepInv) {
		val_DepInv = x;
		isSet_val_DepInv = true;
	}
	if(msg.port() == Workers) {
		val_Workers = x;
		isSet_val_Workers = true;
	}
	if(msg.port() == BankersNW) {
		val_BankersNW = x;
		isSet_val_BankersNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Money::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Money::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_DepCons & isSet_val_DepInv & isSet_val_Workers & isSet_val_BankersNW ) {
		double val = (((val_DepCons+val_DepInv)+val_Workers)+val_BankersNW);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}