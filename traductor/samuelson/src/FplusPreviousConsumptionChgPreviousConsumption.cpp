#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPreviousConsumptionChgPreviousConsumption.h"

using namespace std;

FplusPreviousConsumptionChgPreviousConsumption::FplusPreviousConsumptionChgPreviousConsumption(const string &name) :
	Atomic(name),
	in_timestep(addInputPort("in_timestep")),
	in_previousconsumptionIntegrator(addInputPort("in_previousconsumptionIntegrator")),
	in_consumption(addInputPort("in_consumption")),
	isSet_timestep(false),
	isSet_previousconsumptionIntegrator(false),
	isSet_consumption(false),
	out(addOutputPort("out"))
{
}


Model &FplusPreviousConsumptionChgPreviousConsumption::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPreviousConsumptionChgPreviousConsumption::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_timestep) {
		timestep = x;
		isSet_timestep = true;
	}
	if(msg.port() == in_previousconsumptionIntegrator) {
		previousconsumptionIntegrator = x;
		isSet_previousconsumptionIntegrator = true;
	}
	if(msg.port() == in_consumption) {
		consumption = x;
		isSet_consumption = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPreviousConsumptionChgPreviousConsumption::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPreviousConsumptionChgPreviousConsumption::outputFunction(const CollectMessage &msg)
{
	if( isSet_timestep & isSet_previousconsumptionIntegrator & isSet_consumption ) {
		double val = (consumption - previousconsumptionIntegrator) / timestep;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}