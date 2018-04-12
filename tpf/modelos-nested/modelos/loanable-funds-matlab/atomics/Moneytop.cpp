#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Moneytop.h"

using namespace std;

Moneytop::Moneytop(const string &name) :
	Atomic(name),
    in_port_BankersNW(addInputPort("in_port_BankersNW")),
    in_port_Workers(addInputPort("in_port_Workers")),
    in_port_DepInv(addInputPort("in_port_DepInv")),
    in_port_DepCons(addInputPort("in_port_DepCons")),
    isSet_BankersNW(false),
    isSet_Workers(false),
    isSet_DepInv(false),
    isSet_DepCons(false),
	out_port_Money(addOutputPort("out_port_Money"))
{
}


Model &Moneytop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Moneytop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_BankersNW) {
		BankersNW = x;
		isSet_BankersNW = true;
	}
	if(msg.port() == in_port_Workers) {
		Workers = x;
		isSet_Workers = true;
	}
	if(msg.port() == in_port_DepInv) {
		DepInv = x;
		isSet_DepInv = true;
	}
	if(msg.port() == in_port_DepCons) {
		DepCons = x;
		isSet_DepCons = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Moneytop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Moneytop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_BankersNW & isSet_Workers & isSet_DepInv & isSet_DepCons ) {
	    Tuple<Real> out_value { (((DepCons+DepInv)+Workers)+BankersNW) };
		sendOutput(msg.time(), out_port_Money, out_value);
	}
	
	return *this ;
}