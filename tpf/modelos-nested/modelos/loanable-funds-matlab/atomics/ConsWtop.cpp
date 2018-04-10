#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConsWtop.h"

using namespace std;

ConsWtop::ConsWtop(const string &name) :
	Atomic(name),
    in_port_Workers(addInputPort("in_port_Workers")),
    in_port_tauWC(addInputPort("in_port_tauWC")),
    isSet_Workers(false),
    isSet_tauWC(false),
	out_port_ConsW(addOutputPort("out_port_ConsW"))
{
}


Model &ConsWtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConsWtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Workers) {
		Workers = x;
		isSet_Workers = true;
	}
	if(msg.port() == in_port_tauWC) {
		tauWC = x;
		isSet_tauWC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConsWtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConsWtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Workers & isSet_tauWC ) {
	    Tuple<Real> out_value { (Workers/tauWC) };
		sendOutput(msg.time(), out_port_ConsW, out_value);
	}
	
	return *this ;
}