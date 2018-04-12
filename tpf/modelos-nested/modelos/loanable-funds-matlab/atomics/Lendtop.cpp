#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Lendtop.h"

using namespace std;

Lendtop::Lendtop(const string &name) :
	Atomic(name),
    in_port_DepCons(addInputPort("in_port_DepCons")),
    in_port_tauL(addInputPort("in_port_tauL")),
    isSet_DepCons(false),
    isSet_tauL(false),
	out_port_Lend(addOutputPort("out_port_Lend"))
{
}


Model &Lendtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Lendtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_DepCons) {
		DepCons = x;
		isSet_DepCons = true;
	}
	if(msg.port() == in_port_tauL) {
		tauL = x;
		isSet_tauL = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Lendtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Lendtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_DepCons & isSet_tauL ) {
	    Tuple<Real> out_value { (DepCons/tauL) };
		sendOutput(msg.time(), out_port_Lend, out_value);
	}
	
	return *this ;
}