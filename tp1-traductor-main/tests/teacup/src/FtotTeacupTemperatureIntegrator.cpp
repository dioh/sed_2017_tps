#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotTeacupTemperatureIntegrator.h"

using namespace std;

FtotTeacupTemperatureIntegrator::FtotTeacupTemperatureIntegrator(const string &name) :
	inMinus_HeatLosstoRoom(addInputPort("inMinus_HeatLosstoRoom")),
	out(addOutputPort("out")),
	val_inMinus_HeatLosstoRoom(0),
	isSet_val_inMinus_HeatLosstoRoom(false),
	Atomic(name)
{
}


Model &FtotTeacupTemperatureIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotTeacupTemperatureIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_HeatLosstoRoom) {
		val_inMinus_HeatLosstoRoom = x;
		isSet_val_inMinus_HeatLosstoRoom = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotTeacupTemperatureIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotTeacupTemperatureIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_HeatLosstoRoom ) {
		minus = minus + val_inMinus_HeatLosstoRoom;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}