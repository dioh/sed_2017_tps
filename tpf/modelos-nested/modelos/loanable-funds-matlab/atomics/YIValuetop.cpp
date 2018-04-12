#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "YIValuetop.h"

using namespace std;

YIValuetop::YIValuetop(const string &name) :
	Atomic(name),
    in_port_tauMI(addInputPort("in_port_tauMI")),
    in_port_DepInv(addInputPort("in_port_DepInv")),
    isSet_tauMI(false),
    isSet_DepInv(false),
	out_port_YIValue(addOutputPort("out_port_YIValue"))
{
}


Model &YIValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &YIValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_tauMI) {
		tauMI = x;
		isSet_tauMI = true;
	}
	if(msg.port() == in_port_DepInv) {
		DepInv = x;
		isSet_DepInv = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &YIValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &YIValuetop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_tauMI & isSet_DepInv ) {
	    Tuple<Real> out_value { (DepInv/tauMI) };
		sendOutput(msg.time(), out_port_YIValue, out_value);
	}
	
	return *this ;
}