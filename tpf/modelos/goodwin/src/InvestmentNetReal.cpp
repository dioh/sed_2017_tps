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
	InvestmentGross(addInputPort("InvestmentGross")),
	Capital(addInputPort("Capital")),
	rateOfAppreciation(addInputPort("rateOfAppreciation")),
	isSet_val_InvestmentGross(false),
	isSet_val_Capital(false),
	isSet_val_rateOfAppreciation(false),
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

	if(msg.port() == InvestmentGross) {
		val_InvestmentGross = x;
		isSet_val_InvestmentGross = true;
	}
	if(msg.port() == Capital) {
		val_Capital = x;
		isSet_val_Capital = true;
	}
	if(msg.port() == rateOfAppreciation) {
		val_rateOfAppreciation = x;
		isSet_val_rateOfAppreciation = true;
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
	if( isSet_val_InvestmentGross & isSet_val_Capital & isSet_val_rateOfAppreciation ) {
		double val = val_InvestmentGross - (val_Capital * val_rateOfAppreciation);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}