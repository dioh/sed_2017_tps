#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvestmentGross.h"

using namespace std;

InvestmentGross::InvestmentGross(const string &name) :
	Atomic(name),
	Profit(addInputPort("Profit")),
	isSet_val_Profit(false),
	out(addOutputPort("out"))
{
}


Model &InvestmentGross::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvestmentGross::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Profit) {
		val_Profit = x;
		isSet_val_Profit = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvestmentGross::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvestmentGross::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Profit ) {
		double val = val_Profit;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}