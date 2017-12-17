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
	in_InvestmentFunctionReal(addInputPort("in_InvestmentFunctionReal")),
	in_Output(addInputPort("in_Output")),
	isSet_InvestmentFunctionReal(false),
	isSet_Output(false),
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

	if(msg.port() == in_InvestmentFunctionReal) {
		InvestmentFunctionReal = x;
		isSet_InvestmentFunctionReal = true;
	}
	if(msg.port() == in_Output) {
		Output = x;
		isSet_Output = true;
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
	if( isSet_InvestmentFunctionReal & isSet_Output ) {
		double val = InvestmentFunctionReal * Output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}