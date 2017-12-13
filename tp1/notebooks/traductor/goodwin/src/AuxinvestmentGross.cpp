#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxinvestmentGross.h"

using namespace std;

AuxinvestmentGross::AuxinvestmentGross(const string &name) :
	Atomic(name),
	in_profit(addInputPort("in_profit")),
	isSet_profit(false),
	out(addOutputPort("out"))
{
}


Model &AuxinvestmentGross::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxinvestmentGross::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_profit) {
		profit = x;
		isSet_profit = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxinvestmentGross::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxinvestmentGross::outputFunction(const CollectMessage &msg)
{
	if( isSet_profit ) {
		double val = profit;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}