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
	Workers(addInputPort("Workers")),
	Firms(addInputPort("Firms")),
	Bank(addInputPort("Bank")),
	isSet_val_Workers(false),
	isSet_val_Firms(false),
	isSet_val_Bank(false),
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

	if(msg.port() == Workers) {
		val_Workers = x;
		isSet_val_Workers = true;
	}
	if(msg.port() == Firms) {
		val_Firms = x;
		isSet_val_Firms = true;
	}
	if(msg.port() == Bank) {
		val_Bank = x;
		isSet_val_Bank = true;
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
	if( isSet_val_Workers & isSet_val_Firms & isSet_val_Bank ) {
		double val = ((val_Workers+val_Firms)+val_Bank);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}