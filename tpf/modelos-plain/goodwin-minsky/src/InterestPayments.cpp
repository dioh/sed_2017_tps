#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InterestPayments.h"

using namespace std;

InterestPayments::InterestPayments(const string &name) :
	Atomic(name),
	Debt(addInputPort("Debt")),
	rateInterestOnLoans(addInputPort("rateInterestOnLoans")),
	isSet_val_Debt(false),
	isSet_val_rateInterestOnLoans(false),
	out(addOutputPort("out"))
{
}


Model &InterestPayments::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InterestPayments::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Debt) {
		val_Debt = x;
		isSet_val_Debt = true;
	}
	if(msg.port() == rateInterestOnLoans) {
		val_rateInterestOnLoans = x;
		isSet_val_rateInterestOnLoans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InterestPayments::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InterestPayments::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Debt & isSet_val_rateInterestOnLoans ) {
		double val = val_Debt * val_rateInterestOnLoans;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}