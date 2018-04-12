#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "YCValuetop.h"

using namespace std;

YCValuetop::YCValuetop(const string &name) :
	Atomic(name),
    in_port_DepCons(addInputPort("in_port_DepCons")),
    in_port_tauMC(addInputPort("in_port_tauMC")),
    isSet_DepCons(false),
    isSet_tauMC(false),
	out_port_YCValue(addOutputPort("out_port_YCValue"))
{
}


Model &YCValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &YCValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_DepCons) {
		DepCons = x;
		isSet_DepCons = true;
	}
	if(msg.port() == in_port_tauMC) {
		tauMC = x;
		isSet_tauMC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &YCValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &YCValuetop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_DepCons & isSet_tauMC ) {
	    Tuple<Real> out_value { (DepCons/tauMC) };
		sendOutput(msg.time(), out_port_YCValue, out_value);
	}
	
	return *this ;
}