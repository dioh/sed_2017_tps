#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusTeacup.h"

using namespace std;

FminusTeacup::FminusTeacup(const string &name) :
	Atomic(name),
	inTeacupTemperature(addInputPort("inTeacupTemperature")),
	inCharacteristicTime(addInputPort("inCharacteristicTime")),
	inRoomTemperature(addInputPort("inRoomTemperature")),
	isSetTeacupTemperature(false),
	isSetCharacteristicTime(false),
	isSetRoomTemperature(false),
	out(addOutputPort("out"))
{
}


Model &FminusTeacup::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusTeacup::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inTeacupTemperature) {
		teacupTemperature = x;
		isSetTeacupTemperature = true;
	}
	if(msg.port() == inCharacteristicTime) {
		characteristicTime = x;
		isSetCharacteristicTime = true;
	}
	if(msg.port() == inRoomTemperature) {
		roomTemperature = x;
		isSetRoomTemperature = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusTeacup::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusTeacup::outputFunction(const CollectMessage &msg)
{
	if( isSetTeacupTemperature && isSetCharacteristicTime && isSetRoomTemperature ) {
		double val = (teacupTemperature - roomTemperature) / characteristicTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}