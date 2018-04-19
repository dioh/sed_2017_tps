#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotTemperatureValue.h"

using namespace std;

TotTemperatureValue::TotTemperatureValue(const string &name) :
	Atomic(name),
	in_minus_port_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(addInputPort("in_minus_port_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue")),
	isSet_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(false),
	out_port_TotTemperatureValue(addOutputPort("out_port_TotTemperatureValue"))
	{
}


Model &TotTemperatureValue::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotTemperatureValue::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_minus_port_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue) {
		HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue = x;
		isSet_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotTemperatureValue::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotTemperatureValue::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue) {
		minus = minus + HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotTemperatureValue, out_value);
		}

	return *this ;
}