#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "rateInterestOnLoanstop.h"

using namespace std;

rateInterestOnLoanstop::rateInterestOnLoanstop(const string &name) :
   	in_port_rateInterestOnLoans(addInputPort("in_port_rateInterestOnLoans")),
    out_port_rateInterestOnLoans(addOutputPort("out_port_rateInterestOnLoans")),
    rateInterestOnLoans(-1),
    Atomic(name)
{
}


Model &rateInterestOnLoanstop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &rateInterestOnLoanstop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_rateInterestOnLoans) {
    	rateInterestOnLoans = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &rateInterestOnLoanstop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &rateInterestOnLoanstop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { rateInterestOnLoans };
	sendOutput(msg.time(),  out_port_rateInterestOnLoans, out_value);
    return *this ;
}