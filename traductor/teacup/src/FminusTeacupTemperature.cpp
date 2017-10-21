#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusTeacupTemperature.h"

using namespace std;

FminusTeacupTemperature::FminusTeacupTemperature(const string &name) :
	Atomic(name),
	inTeacupTemperatureIntegrator(addInputPort("inTeacupTemperatureIntegrator")),
	inRoomTemperature(addInputPort("inRoomTemperature")),
	inCharacteristicTime(addInputPort("inCharacteristicTime")),
	isSetTeacupTemperatureIntegrator(false),
	isSetRoomTemperature(false),
	isSetCharacteristicTime(false),
	out(addOutputPort("out"))
{
}


Model &FminusTeacupTemperature::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusTeacupTemperature::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inTeacupTemperatureIntegrator) {
		teacupTemperatureIntegrator = x;
		isSetTeacupTemperatureIntegrator = true;
	}
	if(msg.port() == inRoomTemperature) {
		roomTemperature = x;
		isSetRoomTemperature = true;
	}
	if(msg.port() == inCharacteristicTime) {
		characteristicTime = x;
		isSetCharacteristicTime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusTeacupTemperature::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusTeacupTemperature::outputFunction(const CollectMessage &msg)
{
	if( isSetTeacupTemperatureIntegrator && isSetRoomTemperature && isSetCharacteristicTime ) {
		double val = (teacupTemperatureIntegrator-roomTemperature)/characteristicTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}