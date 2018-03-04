#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusDebtchgDebt.h"

using namespace std;

FplusDebtchgDebt::FplusDebtchgDebt(const string &name) :
	Atomic(name),
	in_investmentGross(addInputPort("in_investmentGross")),
	isSet_investmentGross(false),
	out(addOutputPort("out"))
{
}


Model &FplusDebtchgDebt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusDebtchgDebt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_investmentGross) {
		investmentGross = x;
		isSet_investmentGross = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusDebtchgDebt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusDebtchgDebt::outputFunction(const CollectMessage &msg)
{
	if( isSet_investmentGross ) {
		double val = investmentGross;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}