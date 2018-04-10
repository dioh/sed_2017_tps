#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvestmentFunctionRealtop.h"

using namespace std;

InvestmentFunctionRealtop::InvestmentFunctionRealtop(const string &name) :
	Atomic(name),
    in_port_piR(addInputPort("in_port_piR")),
    in_port_piZ(addInputPort("in_port_piZ")),
    in_port_piS(addInputPort("in_port_piS")),
    isSet_piR(false),
    isSet_piZ(false),
    isSet_piS(false),
	out_port_InvestmentFunctionReal(addOutputPort("out_port_InvestmentFunctionReal"))
{
}


Model &InvestmentFunctionRealtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvestmentFunctionRealtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_piR) {
		piR = x;
		isSet_piR = true;
	}
	if(msg.port() == in_port_piZ) {
		piZ = x;
		isSet_piZ = true;
	}
	if(msg.port() == in_port_piS) {
		piS = x;
		isSet_piS = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvestmentFunctionRealtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvestmentFunctionRealtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_piR & isSet_piZ & isSet_piS ) {
	    Tuple<Real> out_value { ((piR-piZ)*piS) };
		sendOutput(msg.time(), out_port_InvestmentFunctionReal, out_value);
	}
	
	return *this ;
}