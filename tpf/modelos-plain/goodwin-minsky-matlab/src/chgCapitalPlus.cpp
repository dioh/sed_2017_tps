#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgCapitalPlus.h"

using namespace std;

chgCapitalPlus::chgCapitalPlus(const string &name) :
	Atomic(name),
	InvestmentNetReal(addInputPort("InvestmentNetReal")),
	isSet_val_InvestmentNetReal(false),
	out(addOutputPort("out"))
{
}


Model &chgCapitalPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgCapitalPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == InvestmentNetReal) {
		val_InvestmentNetReal = x;
		isSet_val_InvestmentNetReal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgCapitalPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgCapitalPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_InvestmentNetReal ) {
		double val = val_InvestmentNetReal;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}