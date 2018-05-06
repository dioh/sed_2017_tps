#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ProfitNettop.h"

using namespace std;

ProfitNettop::ProfitNettop(const string &name) :
	Atomic(name),
    in_port_ProfitGrossReal(addInputPort("in_port_ProfitGrossReal")),
    in_port_Interest(addInputPort("in_port_Interest")),
    isSet_ProfitGrossReal(false),
    isSet_Interest(false),
	out_port_ProfitNet(addOutputPort("out_port_ProfitNet"))
{
}


Model &ProfitNettop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ProfitNettop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_ProfitGrossReal) {
		ProfitGrossReal = x;
		isSet_ProfitGrossReal = true;
	}
	if(msg.port() == in_port_Interest) {
		Interest = x;
		isSet_Interest = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ProfitNettop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ProfitNettop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_ProfitGrossReal & isSet_Interest ) {
	    Tuple<Real> out_value { (ProfitGrossReal-Interest) };
		sendOutput(msg.time(), out_port_ProfitNet, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_ProfitNet, out_value);
	}
	
	return *this ;
}