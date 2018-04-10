#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue.h"

using namespace std;

HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(const string &name) :
	Atomic(name),
    in_port_TemperatureValue(addInputPort("in_port_TemperatureValue")),
    in_port_RoomTemperature(addInputPort("in_port_RoomTemperature")),
    in_port_CharacteristicTime(addInputPort("in_port_CharacteristicTime")),
    isSet_TemperatureValue(false),
    isSet_RoomTemperature(false),
    isSet_CharacteristicTime(false),
	out_port_HeatLossToRoom_TemperatureValue(addOutputPort("out_port_HeatLossToRoom_TemperatureValue"))
{
}


Model &HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_TemperatureValue) {
		TemperatureValue = x;
		isSet_TemperatureValue = true;
	}
	if(msg.port() == in_port_RoomTemperature) {
		RoomTemperature = x;
		isSet_RoomTemperature = true;
	}
	if(msg.port() == in_port_CharacteristicTime) {
		CharacteristicTime = x;
		isSet_CharacteristicTime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_TemperatureValue & isSet_RoomTemperature & isSet_CharacteristicTime ) {
	    Tuple<Real> out_value { (TemperatureValue - RoomTemperature) / CharacteristicTime };
		sendOutput(msg.time(), out_port_HeatLossToRoom_TemperatureValue, out_value);
	}
	
	return *this ;
}