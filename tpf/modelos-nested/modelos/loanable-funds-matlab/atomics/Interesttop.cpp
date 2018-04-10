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
    in_port_rLValue(addInputPort("in_port_rLValue")),
    in_port_Loans(addInputPort("in_port_Loans")),
    isSet_rLValue(false),
    isSet_Loans(false),
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

	if(msg.port() == in_port_rLValue) {
		rLValue = x;
		isSet_rLValue = true;
	}
	if(msg.port() == in_port_Loans) {
		Loans = x;
		isSet_Loans = true;
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
	
	if( isSet_rLValue & isSet_Loans ) {
	    Tuple<Real> out_value { (rLValue*Loans) };
		sendOutput(msg.time(), out_port_Interest, out_value);
	}
	
	return *this ;
}