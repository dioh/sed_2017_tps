#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "HeatLossToRoomMinus.h"

using namespace std;

HeatLossToRoomMinus::HeatLossToRoomMinus(const string &name) :
	Atomic(name),
	TemperatureValue(addInputPort("TemperatureValue")),
	RoomTemperature(addInputPort("RoomTemperature")),
	CharacteristicTime(addInputPort("CharacteristicTime")),
	isSet_val_TemperatureValue(false),
	isSet_val_RoomTemperature(false),
	isSet_val_CharacteristicTime(false),
	out(addOutputPort("out"))
{
}


Model &HeatLossToRoomMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &HeatLossToRoomMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == TemperatureValue) {
		val_TemperatureValue = x;
		isSet_val_TemperatureValue = true;
	}
	if(msg.port() == RoomTemperature) {
		val_RoomTemperature = x;
		isSet_val_RoomTemperature = true;
	}
	if(msg.port() == CharacteristicTime) {
		val_CharacteristicTime = x;
		isSet_val_CharacteristicTime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &HeatLossToRoomMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &HeatLossToRoomMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_TemperatureValue & isSet_val_RoomTemperature & isSet_val_CharacteristicTime ) {
		double val = (val_TemperatureValue - val_RoomTemperature) / val_CharacteristicTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}