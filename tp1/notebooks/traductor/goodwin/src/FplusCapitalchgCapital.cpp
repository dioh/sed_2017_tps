#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusCapitalchgCapital.h"

using namespace std;

FplusCapitalchgCapital::FplusCapitalchgCapital(const string &name) :
	Atomic(name),
	in_investmentNetReal(addInputPort("in_investmentNetReal")),
	isSet_investmentNetReal(false),
	out(addOutputPort("out"))
{
}


Model &FplusCapitalchgCapital::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusCapitalchgCapital::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_investmentNetReal) {
		investmentNetReal = x;
		isSet_investmentNetReal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusCapitalchgCapital::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusCapitalchgCapital::outputFunction(const CollectMessage &msg)
{
	if( isSet_investmentNetReal ) {
		double val = investmentNetReal;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}