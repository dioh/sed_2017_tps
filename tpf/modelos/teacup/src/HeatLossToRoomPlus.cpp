#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "HeatLossToRoomPlus.h"

using namespace std;

HeatLossToRoomPlus::HeatLossToRoomPlus(const string &name) :
	Atomic(name),
	Temperature(addInputPort("Temperature")),
	RoomTemperature(addInputPort("RoomTemperature")),
	CharacteristicTime(addInputPort("CharacteristicTime")),
	isSet_val_Temperature(false),
	isSet_val_RoomTemperature(false),
	isSet_val_CharacteristicTime(false),
	out(addOutputPort("out"))
{
}


Model &HeatLossToRoomPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &HeatLossToRoomPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Temperature) {
		val_Temperature = x;
		isSet_val_Temperature = true;
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


Model &HeatLossToRoomPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &HeatLossToRoomPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Temperature & isSet_val_RoomTemperature & isSet_val_CharacteristicTime ) {
		double val = (val_Temperature - Roomval_Temperature) / val_CharacteristicTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}