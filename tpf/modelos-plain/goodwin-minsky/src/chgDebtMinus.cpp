#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgDebtMinus.h"

using namespace std;

chgDebtMinus::chgDebtMinus(const string &name) :
	Atomic(name),
	InvestmentGross(addInputPort("InvestmentGross")),
	isSet_val_InvestmentGross(false),
	out(addOutputPort("out"))
{
}


Model &chgDebtMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgDebtMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == InvestmentGross) {
		val_InvestmentGross = x;
		isSet_val_InvestmentGross = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgDebtMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgDebtMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_InvestmentGross ) {
		double val = val_InvestmentGross;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}