#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConsBtop.h"

using namespace std;

ConsBtop::ConsBtop(const string &name) :
	Atomic(name),
    in_port_BankersNW(addInputPort("in_port_BankersNW")),
    in_port_tauBC(addInputPort("in_port_tauBC")),
    isSet_BankersNW(false),
    isSet_tauBC(false),
	out_port_ConsB(addOutputPort("out_port_ConsB"))
{
}


Model &ConsBtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConsBtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_BankersNW) {
		BankersNW = x;
		isSet_BankersNW = true;
	}
	if(msg.port() == in_port_tauBC) {
		tauBC = x;
		isSet_tauBC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConsBtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConsBtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_BankersNW & isSet_tauBC ) {
	    Tuple<Real> out_value { (BankersNW/tauBC) };
		sendOutput(msg.time(), out_port_ConsB, out_value);
	}
	
	return *this ;
}