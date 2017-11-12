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
	in_Investment(addInputPort("in_Investment")),
	in_Consumption(addInputPort("in_Consumption")),
	in_governmentSpending(addInputPort("in_governmentSpending")),
	isSet_Investment(false),
	isSet_Consumption(false),
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

	if(msg.port() == in_Investment) {
		Investment = x;
		isSet_Investment = true;
	}
	if(msg.port() == in_Consumption) {
		Consumption = x;
		isSet_Consumption = true;
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
	if( isSet_Investment & isSet_Consumption & isSet_governmentSpending ) {
		double val = Investment + Consumption + governmentSpending;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}