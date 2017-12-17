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
	in_output(addInputPort("in_output")),
	in_investmentFunctionReal(addInputPort("in_investmentFunctionReal")),
	isSet_output(false),
	isSet_investmentFunctionReal(false),
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

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_investmentFunctionReal) {
		investmentFunctionReal = x;
		isSet_investmentFunctionReal = true;
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
	if( isSet_output & isSet_investmentFunctionReal ) {
		double val = investmentFunctionReal * output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}