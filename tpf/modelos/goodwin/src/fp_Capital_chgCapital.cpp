#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_Capital_chgCapital.h"

using namespace std;

fp_Capital_chgCapital::fp_Capital_chgCapital(const string &name) :
	Atomic(name),
	in_InvestmentNetReal(addInputPort("in_InvestmentNetReal")),
	isSet_InvestmentNetReal(false),
	out(addOutputPort("out"))

{
}


Model &fp_Capital_chgCapital::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_Capital_chgCapital::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_InvestmentNetReal) {
		InvestmentNetReal = x;
		isSet_InvestmentNetReal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_Capital_chgCapital::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_Capital_chgCapital::outputFunction(const CollectMessage &msg)
{
	if( isSet_InvestmentNetReal ) {
		double val = InvestmentNetReal;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}