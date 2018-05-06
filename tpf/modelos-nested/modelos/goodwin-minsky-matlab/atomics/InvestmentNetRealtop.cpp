#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvestmentNetRealtop.h"

using namespace std;

InvestmentNetRealtop::InvestmentNetRealtop(const string &name) :
	Atomic(name),
    in_port_InvestmentGross(addInputPort("in_port_InvestmentGross")),
    in_port_deltaKReal(addInputPort("in_port_deltaKReal")),
    in_port_Capital(addInputPort("in_port_Capital")),
    isSet_InvestmentGross(false),
    isSet_deltaKReal(false),
    isSet_Capital(false),
	out_port_InvestmentNetReal(addOutputPort("out_port_InvestmentNetReal"))
{
}


Model &InvestmentNetRealtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvestmentNetRealtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_InvestmentGross) {
		InvestmentGross = x;
		isSet_InvestmentGross = true;
	}
	if(msg.port() == in_port_deltaKReal) {
		deltaKReal = x;
		isSet_deltaKReal = true;
	}
	if(msg.port() == in_port_Capital) {
		Capital = x;
		isSet_Capital = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvestmentNetRealtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvestmentNetRealtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_InvestmentGross & isSet_deltaKReal & isSet_Capital ) {
	    Tuple<Real> out_value { (InvestmentGross-(Capital*deltaKReal)) };
		sendOutput(msg.time(), out_port_InvestmentNetReal, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_InvestmentNetReal, out_value);
	}
	
	return *this ;
}