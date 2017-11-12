#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxoutput.h"

using namespace std;

Auxoutput::Auxoutput(const string &name) :
	Atomic(name),
	in_investment(addInputPort("in_investment")),
	in_consumption(addInputPort("in_consumption")),
	in_governmentSpending(addInputPort("in_governmentSpending")),
	isSet_investment(false),
	isSet_consumption(false),
	isSet_governmentSpending(false),
	out(addOutputPort("out"))
{
}


Model &Auxoutput::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxoutput::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_investment) {
		investment = x;
		isSet_investment = true;
	}
	if(msg.port() == in_consumption) {
		consumption = x;
		isSet_consumption = true;
	}
	if(msg.port() == in_governmentSpending) {
		governmentSpending = x;
		isSet_governmentSpending = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxoutput::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxoutput::outputFunction(const CollectMessage &msg)
{
	if( isSet_investment & isSet_consumption & isSet_governmentSpending ) {
		double val = investment + consumption + governmentSpending;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}