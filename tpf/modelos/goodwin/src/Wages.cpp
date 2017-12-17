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
	in_WageRate(addInputPort("in_WageRate")),
	in_Labor(addInputPort("in_Labor")),
	isSet_WageRate(false),
	isSet_Labor(false),
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

	if(msg.port() == in_WageRate) {
		WageRate = x;
		isSet_WageRate = true;
	}
	if(msg.port() == in_Labor) {
		Labor = x;
		isSet_Labor = true;
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
	if( isSet_WageRate & isSet_Labor ) {
		double val = WageRate * Labor;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}