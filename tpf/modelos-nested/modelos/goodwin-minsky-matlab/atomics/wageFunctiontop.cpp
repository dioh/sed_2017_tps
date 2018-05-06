#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "wageFunctiontop.h"

using namespace std;

wageFunctiontop::wageFunctiontop(const string &name) :
	Atomic(name),
    in_port_employmentRateStable(addInputPort("in_port_employmentRateStable")),
    in_port_employmentRateZero(addInputPort("in_port_employmentRateZero")),
    in_port_employmentRateValue(addInputPort("in_port_employmentRateValue")),
    isSet_employmentRateStable(false),
    isSet_employmentRateZero(false),
    isSet_employmentRateValue(false),
	out_port_wageFunction(addOutputPort("out_port_wageFunction"))
{
}


Model &wageFunctiontop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &wageFunctiontop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_employmentRateStable) {
		employmentRateStable = x;
		isSet_employmentRateStable = true;
	}
	if(msg.port() == in_port_employmentRateZero) {
		employmentRateZero = x;
		isSet_employmentRateZero = true;
	}
	if(msg.port() == in_port_employmentRateValue) {
		employmentRateValue = x;
		isSet_employmentRateValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &wageFunctiontop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &wageFunctiontop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_employmentRateStable & isSet_employmentRateZero & isSet_employmentRateValue ) {
	    Tuple<Real> out_value { (employmentRateStable*(employmentRateValue-employmentRateZero)) };
		sendOutput(msg.time(), out_port_wageFunction, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_wageFunction, out_value);
	}
	
	return *this ;
}