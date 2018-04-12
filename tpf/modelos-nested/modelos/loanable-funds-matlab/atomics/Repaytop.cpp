#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Repaytop.h"

using namespace std;

Repaytop::Repaytop(const string &name) :
	Atomic(name),
    in_port_Loans(addInputPort("in_port_Loans")),
    in_port_tauR(addInputPort("in_port_tauR")),
    isSet_Loans(false),
    isSet_tauR(false),
	out_port_Repay(addOutputPort("out_port_Repay"))
{
}


Model &Repaytop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Repaytop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Loans) {
		Loans = x;
		isSet_Loans = true;
	}
	if(msg.port() == in_port_tauR) {
		tauR = x;
		isSet_tauR = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Repaytop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Repaytop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Loans & isSet_tauR ) {
	    Tuple<Real> out_value { (Loans/tauR) };
		sendOutput(msg.time(), out_port_Repay, out_value);
	}
	
	return *this ;
}