#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Interesttop.h"

using namespace std;

Interesttop::Interesttop(const string &name) :
	Atomic(name),
    in_port_Debt(addInputPort("in_port_Debt")),
    in_port_rateInterestOnLoans(addInputPort("in_port_rateInterestOnLoans")),
    isSet_Debt(false),
    isSet_rateInterestOnLoans(false),
	out_port_Interest(addOutputPort("out_port_Interest"))
{
}


Model &Interesttop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Interesttop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Debt) {
		Debt = x;
		isSet_Debt = true;
	}
	if(msg.port() == in_port_rateInterestOnLoans) {
		rateInterestOnLoans = x;
		isSet_rateInterestOnLoans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Interesttop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Interesttop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Debt & isSet_rateInterestOnLoans ) {
	    Tuple<Real> out_value { (rateInterestOnLoans*Debt) };
		sendOutput(msg.time(), out_port_Interest, out_value);
	}
	
	return *this ;
}