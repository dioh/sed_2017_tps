#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvestmentGrosstop.h"

using namespace std;

InvestmentGrosstop::InvestmentGrosstop(const string &name) :
	Atomic(name),
    in_port_InvestmentFunctionReal(addInputPort("in_port_InvestmentFunctionReal")),
    in_port_Output(addInputPort("in_port_Output")),
    isSet_InvestmentFunctionReal(false),
    isSet_Output(false),
	out_port_InvestmentGross(addOutputPort("out_port_InvestmentGross"))
{
}


Model &InvestmentGrosstop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvestmentGrosstop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_InvestmentFunctionReal) {
		InvestmentFunctionReal = x;
		isSet_InvestmentFunctionReal = true;
	}
	if(msg.port() == in_port_Output) {
		Output = x;
		isSet_Output = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvestmentGrosstop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvestmentGrosstop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_InvestmentFunctionReal & isSet_Output ) {
	    Tuple<Real> out_value { (InvestmentFunctionReal*Output) };
		sendOutput(msg.time(), out_port_InvestmentGross, out_value);
	}
	
	return *this ;
}