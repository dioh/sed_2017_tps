#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Interest.h"

using namespace std;

Interest::Interest(const string &name) :
	Atomic(name),
	rateInterestOnLoans(addInputPort("rateInterestOnLoans")),
	Debt(addInputPort("Debt")),
	isSet_val_rateInterestOnLoans(false),
	isSet_val_Debt(false),
	out(addOutputPort("out"))
{
}


Model &Interest::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Interest::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == rateInterestOnLoans) {
		val_rateInterestOnLoans = x;
		isSet_val_rateInterestOnLoans = true;
	}
	if(msg.port() == Debt) {
		val_Debt = x;
		isSet_val_Debt = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Interest::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Interest::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_rateInterestOnLoans & isSet_val_Debt ) {
		double val = (val_rateInterestOnLoans*val_Debt);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}