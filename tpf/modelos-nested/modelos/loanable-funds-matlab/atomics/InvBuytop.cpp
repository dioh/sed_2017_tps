#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvBuytop.h"

using namespace std;

InvBuytop::InvBuytop(const string &name) :
	Atomic(name),
    in_port_IPCValue(addInputPort("in_port_IPCValue")),
    in_port_PiIG(addInputPort("in_port_PiIG")),
    isSet_IPCValue(false),
    isSet_PiIG(false),
	out_port_InvBuy(addOutputPort("out_port_InvBuy"))
{
}


Model &InvBuytop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvBuytop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_IPCValue) {
		IPCValue = x;
		isSet_IPCValue = true;
	}
	if(msg.port() == in_port_PiIG) {
		PiIG = x;
		isSet_PiIG = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvBuytop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvBuytop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_IPCValue & isSet_PiIG ) {
	    Tuple<Real> out_value { (PiIG*IPCValue) };
		sendOutput(msg.time(), out_port_InvBuy, out_value);
	}
	
	return *this ;
}