#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "IntFeetop.h"

using namespace std;

IntFeetop::IntFeetop(const string &name) :
	Atomic(name),
    in_port_bfValue(addInputPort("in_port_bfValue")),
    in_port_Interest(addInputPort("in_port_Interest")),
    isSet_bfValue(false),
    isSet_Interest(false),
	out_port_IntFee(addOutputPort("out_port_IntFee"))
{
}


Model &IntFeetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &IntFeetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_bfValue) {
		bfValue = x;
		isSet_bfValue = true;
	}
	if(msg.port() == in_port_Interest) {
		Interest = x;
		isSet_Interest = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &IntFeetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &IntFeetop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_bfValue & isSet_Interest ) {
	    Tuple<Real> out_value { (Interest*bfValue) };
		sendOutput(msg.time(), out_port_IntFee, out_value);
	}
	
	return *this ;
}