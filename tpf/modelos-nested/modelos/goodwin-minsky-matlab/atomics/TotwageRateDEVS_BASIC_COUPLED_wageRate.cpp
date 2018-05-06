#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotwageRateDEVS_BASIC_COUPLED_wageRate.h"

using namespace std;

TotwageRateDEVS_BASIC_COUPLED_wageRate::TotwageRateDEVS_BASIC_COUPLED_wageRate(const string &name) :
	Atomic(name),
	in_plus_port_chgwageRate_wageRate(addInputPort("in_plus_port_chgwageRate_wageRate")),
	isSet_chgwageRate_wageRate(false),
	out_port_TotwageRate(addOutputPort("out_port_TotwageRate"))
	{
}


Model &TotwageRateDEVS_BASIC_COUPLED_wageRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotwageRateDEVS_BASIC_COUPLED_wageRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgwageRate_wageRate) {
		chgwageRate_wageRate = x;
		isSet_chgwageRate_wageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotwageRateDEVS_BASIC_COUPLED_wageRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotwageRateDEVS_BASIC_COUPLED_wageRate::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_chgwageRate_wageRate) { plus = plus + chgwageRate_wageRate; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotwageRate, out_value);
	return *this ;
}