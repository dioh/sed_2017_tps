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
    TemperatureValue(addInputPort("TemperatureValue")),
    RoomTemperature(addInputPort("RoomTemperature")),
    CharacteristicTime(addInputPort("CharacteristicTime")),
    isSet_TemperatureValue(false),
    isSet_RoomTemperature(false),
    isSet_CharacteristicTime(false),
	HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(addOutputPort("HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue"))
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

	if(msg.port() == TemperatureValue) {
		TemperatureValue = x;
		isSet_TemperatureValue = true;
	}
	if(msg.port() == RoomTemperature) {
		RoomTemperature = x;
		isSet_RoomTemperature = true;
	}
	if(msg.port() == CharacteristicTime) {
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
		sendOutput(msg.time(), HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue, out_value);
	}
	
	return *this ;
}