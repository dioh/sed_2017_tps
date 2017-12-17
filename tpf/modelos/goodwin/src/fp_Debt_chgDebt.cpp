#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_Debt_chgDebt.h"

using namespace std;

fp_Debt_chgDebt::fp_Debt_chgDebt(const string &name) :
	Atomic(name),
	in_InvestmentGross(addInputPort("in_InvestmentGross")),
	isSet_InvestmentGross(false),
	out(addOutputPort("out"))

{
}


Model &fp_Debt_chgDebt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_Debt_chgDebt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_InvestmentGross) {
		InvestmentGross = x;
		isSet_InvestmentGross = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_Debt_chgDebt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_Debt_chgDebt::outputFunction(const CollectMessage &msg)
{
	if( isSet_InvestmentGross ) {
		double val = InvestmentGross;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}