#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "piRtop.h"

using namespace std;

piRtop::piRtop(const string &name) :
	Atomic(name),
    in_port_Capital(addInputPort("in_port_Capital")),
    in_port_ProfitNet(addInputPort("in_port_ProfitNet")),
    isSet_Capital(false),
    isSet_ProfitNet(false),
	out_port_piR(addOutputPort("out_port_piR"))
{
}


Model &piRtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &piRtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Capital) {
		Capital = x;
		isSet_Capital = true;
	}
	if(msg.port() == in_port_ProfitNet) {
		ProfitNet = x;
		isSet_ProfitNet = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &piRtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &piRtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Capital & isSet_ProfitNet ) {
	    Tuple<Real> out_value { (ProfitNet/Capital) };
		sendOutput(msg.time(), out_port_piR, out_value);
	}
	
	return *this ;
}