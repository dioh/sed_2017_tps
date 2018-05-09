#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"

using namespace std;

TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(const string &name) :
	Atomic(name),
	in_minus_port_HeatLossToRoom_TemperatureValue(addInputPort("in_minus_port_HeatLossToRoom_TemperatureValue")),
	isSet_HeatLossToRoom_TemperatureValue(false),
	out_port_TotTemperatureValue(addOutputPort("out_port_TotTemperatureValue"))
	{
}


Model &TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_minus_port_HeatLossToRoom_TemperatureValue) {
		HeatLossToRoom_TemperatureValue = x;
		isSet_HeatLossToRoom_TemperatureValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_HeatLossToRoom_TemperatureValue) { minus = minus + HeatLossToRoom_TemperatureValue; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotTemperatureValue, out_value);
	return *this ;
}