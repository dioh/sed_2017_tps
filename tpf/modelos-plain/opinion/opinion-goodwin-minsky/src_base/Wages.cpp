#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Wages.h"

using namespace std;

Wages::Wages(const string &name) :
	Atomic(name),
	WageRate(addInputPort("WageRate")),
	Labor(addInputPort("Labor")),
	isSet_val_WageRate(false),
	isSet_val_Labor(false),
	out(addOutputPort("out"))
{
}


Model &Wages::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Wages::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == WageRate) {
		val_WageRate = x;
		isSet_val_WageRate = true;
	}
	if(msg.port() == Labor) {
		val_Labor = x;
		isSet_val_Labor = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Wages::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Wages::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_WageRate & isSet_val_Labor ) {
		double val = val_WageRate * val_Labor;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}