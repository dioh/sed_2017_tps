#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusTeacupTemperatureHeatLosstoRoom.h"

using namespace std;

FminusTeacupTemperatureHeatLosstoRoom::FminusTeacupTemperatureHeatLosstoRoom(const string &name) :
	Atomic(name),
	in_teacupTemperatureIntegrator(addInputPort("in_teacupTemperatureIntegrator")),
	in_roomTemperature(addInputPort("in_roomTemperature")),
	in_characteristicTime(addInputPort("in_characteristicTime")),
	isSet_teacupTemperatureIntegrator(false),
	isSet_roomTemperature(false),
	isSet_characteristicTime(false),
	out(addOutputPort("out"))
{
}


Model &FminusTeacupTemperatureHeatLosstoRoom::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusTeacupTemperatureHeatLosstoRoom::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_teacupTemperatureIntegrator) {
		teacupTemperatureIntegrator = x;
		isSet_teacupTemperatureIntegrator = true;
	}
	if(msg.port() == in_roomTemperature) {
		roomTemperature = x;
		isSet_roomTemperature = true;
	}
	if(msg.port() == in_characteristicTime) {
		characteristicTime = x;
		isSet_characteristicTime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusTeacupTemperatureHeatLosstoRoom::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusTeacupTemperatureHeatLosstoRoom::outputFunction(const CollectMessage &msg)
{
	if( isSet_teacupTemperatureIntegrator & isSet_roomTemperature & isSet_characteristicTime ) {
		double val = (teacupTemperatureIntegrator-roomTemperature)/characteristicTime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}