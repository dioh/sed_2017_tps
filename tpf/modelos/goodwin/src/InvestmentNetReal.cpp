#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvestmentNetReal.h"

using namespace std;

InvestmentNetReal::InvestmentNetReal(const string &name) :
	Atomic(name),
	in_InvestmentGross(addInputPort("in_InvestmentGross")),
	in_Capital(addInputPort("in_Capital")),
	in_deltaKReal(addInputPort("in_deltaKReal")),
	isSet_InvestmentGross(false),
	isSet_Capital(false),
	isSet_deltaKReal(false),
	out(addOutputPort("out"))
{
}


Model &InvestmentNetReal::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvestmentNetReal::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_InvestmentGross) {
		InvestmentGross = x;
		isSet_InvestmentGross = true;
	}
	if(msg.port() == in_Capital) {
		Capital = x;
		isSet_Capital = true;
	}
	if(msg.port() == in_deltaKReal) {
		deltaKReal = x;
		isSet_deltaKReal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvestmentNetReal::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvestmentNetReal::outputFunction(const CollectMessage &msg)
{
	if( isSet_InvestmentGross & isSet_Capital & isSet_deltaKReal ) {
		double val = InvestmentGross - (Capital * deltaKReal);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}