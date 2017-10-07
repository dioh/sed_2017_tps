#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusSusc.h"

using namespace std;

FminusSusc::FminusSusc(const string &name) :
	Atomic(name),
	inSusceptible(addInputPort("inSusceptible")),
	inInfected(addInputPort("inInfected")),
	inContactInfectivity(addInputPort("inContactInfectivity")),
	inTotalPopulation(addInputPort("inTotalPopulation")),
	out(addOutputPort("out")),
	isSetSusceptible(false),
	isSetInfected(false),
	isSetContactInfectivity(false),
	isSetTotalPopulation(false)
{
}


Model &FminusSusc::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusSusc::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inSusceptible) {
		susceptible = x;
		isSetSusceptible = true;
	} else if (msg.port() == inInfected) {
		infected = x;
		isSetInfected = true;
	} else if (msg.port() == inContactInfectivity) {
		contactInfectivity = x;
		isSetContactInfectivity = true;
	} else if (msg.port() == inTotalPopulation) {
		totalPopulation = x;
		isSetTotalPopulation = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusSusc::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusSusc::outputFunction(const CollectMessage &msg)
{
	if(isSetSusceptible && isSetInfected && isSetContactInfectivity && isSetTotalPopulation) {
		double val = (infected * susceptible) / (contactInfectivity * totalPopulation);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}
