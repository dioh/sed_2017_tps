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
	DebtFirms(addInputPort("DebtFirms")),
	rateOfInterestOnLoans(addInputPort("rateOfInterestOnLoans")),
	isSet_val_DebtFirms(false),
	isSet_val_rateOfInterestOnLoans(false),
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

	if(msg.port() == DebtFirms) {
		val_DebtFirms = x;
		isSet_val_DebtFirms = true;
	}
	if(msg.port() == rateOfInterestOnLoans) {
		val_rateOfInterestOnLoans = x;
		isSet_val_rateOfInterestOnLoans = true;
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
	if( isSet_val_DebtFirms & isSet_val_rateOfInterestOnLoans ) {
		double val = (val_DebtFirms*val_rateOfInterestOnLoans);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}