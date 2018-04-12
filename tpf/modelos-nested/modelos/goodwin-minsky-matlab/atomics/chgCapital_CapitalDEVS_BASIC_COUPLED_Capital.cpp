#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgCapital_CapitalDEVS_BASIC_COUPLED_Capital.h"

using namespace std;

chgCapital_CapitalDEVS_BASIC_COUPLED_Capital::chgCapital_CapitalDEVS_BASIC_COUPLED_Capital(const string &name) :
	Atomic(name),
    in_port_InvestmentNetReal(addInputPort("in_port_InvestmentNetReal")),
    isSet_InvestmentNetReal(false),
	out_port_chgCapital_Capital(addOutputPort("out_port_chgCapital_Capital"))
{
}


Model &chgCapital_CapitalDEVS_BASIC_COUPLED_Capital::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgCapital_CapitalDEVS_BASIC_COUPLED_Capital::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_InvestmentNetReal) {
		InvestmentNetReal = x;
		isSet_InvestmentNetReal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgCapital_CapitalDEVS_BASIC_COUPLED_Capital::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgCapital_CapitalDEVS_BASIC_COUPLED_Capital::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_InvestmentNetReal ) {
	    Tuple<Real> out_value { InvestmentNetReal };
		sendOutput(msg.time(), out_port_chgCapital_Capital, out_value);
	}
	
	return *this ;
}