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
	in_Debt(addInputPort("in_Debt")),
	in_rateInterestOnLoans(addInputPort("in_rateInterestOnLoans")),
	isSet_Debt(false),
	isSet_rateInterestOnLoans(false),
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

	if(msg.port() == in_Debt) {
		Debt = x;
		isSet_Debt = true;
	}
	if(msg.port() == in_rateInterestOnLoans) {
		rateInterestOnLoans = x;
		isSet_rateInterestOnLoans = true;
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
	if( isSet_Debt & isSet_rateInterestOnLoans ) {
		double val = Debt * rateInterestOnLoans;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}