#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotwageRate.h"

using namespace std;

TotwageRate::TotwageRate(const string &name) :
	Atomic(name),
	in_plus_port_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate(addInputPort("in_plus_port_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate")),
	isSet_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate(false),
	out_port_TotwageRate(addOutputPort("out_port_TotwageRate"))
	{
}


Model &TotwageRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotwageRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate) {
		chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate = x;
		isSet_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotwageRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotwageRate::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate) {
		plus = plus + chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotwageRate, out_value);
		}

	return *this ;
}