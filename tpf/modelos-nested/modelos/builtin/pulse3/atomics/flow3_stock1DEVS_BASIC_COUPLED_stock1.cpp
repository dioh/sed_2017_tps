#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "flow3_stock1DEVS_BASIC_COUPLED_stock1.h"

using namespace std;

flow3_stock1DEVS_BASIC_COUPLED_stock1::flow3_stock1DEVS_BASIC_COUPLED_stock1(const string &name) :
	Atomic(name),
    in_port_exra(addInputPort("in_port_exra")),
    isSet_exra(false),
	out_port_flow3_stock1(addOutputPort("out_port_flow3_stock1"))
{
}


Model &flow3_stock1DEVS_BASIC_COUPLED_stock1::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &flow3_stock1DEVS_BASIC_COUPLED_stock1::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_exra) {
		exra = x;
		isSet_exra = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &flow3_stock1DEVS_BASIC_COUPLED_stock1::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &flow3_stock1DEVS_BASIC_COUPLED_stock1::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_exra ) {
	    Tuple<Real> out_value { exra };
		sendOutput(msg.time(), out_port_flow3_stock1, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_flow3_stock1, out_value);
	}
	
	return *this ;
}