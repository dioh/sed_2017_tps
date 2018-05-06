#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Wagestop.h"

using namespace std;

Wagestop::Wagestop(const string &name) :
	Atomic(name),
    in_port_Labor(addInputPort("in_port_Labor")),
    in_port_wageRate(addInputPort("in_port_wageRate")),
    isSet_Labor(false),
    isSet_wageRate(false),
	out_port_Wages(addOutputPort("out_port_Wages"))
{
}


Model &Wagestop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Wagestop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Labor) {
		Labor = x;
		isSet_Labor = true;
	}
	if(msg.port() == in_port_wageRate) {
		wageRate = x;
		isSet_wageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Wagestop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Wagestop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Labor & isSet_wageRate ) {
	    Tuple<Real> out_value { (wageRate*Labor) };
		sendOutput(msg.time(), out_port_Wages, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_Wages, out_value);
	}
	
	return *this ;
}