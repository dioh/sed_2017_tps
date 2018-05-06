#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate.h"

using namespace std;

chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate::chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate(const string &name) :
	Atomic(name),
    in_port_wageFunction(addInputPort("in_port_wageFunction")),
    in_port_wageRate(addInputPort("in_port_wageRate")),
    isSet_wageFunction(false),
    isSet_wageRate(false),
	out_port_chgwageRate_wageRate(addOutputPort("out_port_chgwageRate_wageRate"))
{
}


Model &chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_wageFunction) {
		wageFunction = x;
		isSet_wageFunction = true;
	}
	if(msg.port() == in_port_wageRate) {
		wageRate = x;
		isSet_wageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_wageFunction & isSet_wageRate ) {
	    Tuple<Real> out_value { (wageFunction*wageRate) };
		sendOutput(msg.time(), out_port_chgwageRate_wageRate, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_chgwageRate_wageRate, out_value);
	}
	
	return *this ;
}