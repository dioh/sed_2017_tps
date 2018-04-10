#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Debttop.h"

using namespace std;

Debttop::Debttop(const string &name) :
	Atomic(name),
    in_port_Loans(addInputPort("in_port_Loans")),
    isSet_Loans(false),
	out_port_Debt(addOutputPort("out_port_Debt"))
{
}


Model &Debttop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Debttop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Loans) {
		Loans = x;
		isSet_Loans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Debttop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Debttop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Loans ) {
	    Tuple<Real> out_value { Loans };
		sendOutput(msg.time(), out_port_Debt, out_value);
	}
	
	return *this ;
}