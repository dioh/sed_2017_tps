#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxinterestPayments.h"

using namespace std;

AuxinterestPayments::AuxinterestPayments(const string &name) :
	Atomic(name),
	in_debtIntegrator(addInputPort("in_debtIntegrator")),
	in_rateInterestOnLoans(addInputPort("in_rateInterestOnLoans")),
	isSet_debtIntegrator(false),
	isSet_rateInterestOnLoans(false),
	out(addOutputPort("out"))
{
}


Model &AuxinterestPayments::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxinterestPayments::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_debtIntegrator) {
		debtIntegrator = x;
		isSet_debtIntegrator = true;
	}
	if(msg.port() == in_rateInterestOnLoans) {
		rateInterestOnLoans = x;
		isSet_rateInterestOnLoans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxinterestPayments::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxinterestPayments::outputFunction(const CollectMessage &msg)
{
	if( isSet_debtIntegrator & isSet_rateInterestOnLoans ) {
		double val = debtIntegrator * rateInterestOnLoans;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}