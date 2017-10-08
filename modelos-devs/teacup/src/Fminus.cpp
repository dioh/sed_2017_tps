#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Fminus.h"

using namespace std;

Fminus::Fminus(const string &name) :
	Atomic(name),
	inTeacupTemperature(addInputPort("inTeacupTemperature")),
	inRoomTemperature(addInputPort("inRoomTemperature")),
	inCharacteristicTime(addInputPort("inCharacteristicTime")),
	out(addOutputPort("out")),
	isSetTeacupTemperature(false),
	isSetRoomTemperature(false),
	isSetCharacteristicTime(false)
{
}


Model &Fminus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Fminus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inTeacupTemperature) {
		teacupTemperature = x;
		isSetTeacupTemperature = true;
	} else if (msg.port() == inRoomTemperature) {
		roomTemperature = x;
		isSetRoomTemperature = true;
	} else if (msg.port() == inCharacteristicTime) {
		characteristicTime = x;
		isSetCharacteristicTime = true;
	}

	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Fminus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Fminus::outputFunction(const CollectMessage &msg)
{
	if(isSetCharacteristicTime && isSetRoomTemperature && isSetTeacupTemperature) {	
		double val = (teacupTemperature - roomTemperature) / characteristicTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}
