#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusInfected.h"

using namespace std;

FplusInfected::FplusInfected(const string &name) :
	Atomic(name),
	inInfected(addInputPort("inInfected")),
	inSusceptible(addInputPort("inSusceptible")),
	inContactInfectivity(addInputPort("inContactInfectivity")),
	inTotalPopulation(addInputPort("inTotalPopulation")),
	isSetInfected(false),
	isSetSusceptible(false),
	isSetContactInfectivity(false),
	isSetTotalPopulation(false),
	out(addOutputPort("out"))
{
}


Model &FplusInfected::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusInfected::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inInfected) {
		infected = x;
		isSetInfected = true;
	}
	if(msg.port() == inSusceptible) {
		susceptible = x;
		isSetSusceptible = true;
	}
	if(msg.port() == inContactInfectivity) {
		contactInfectivity = x;
		isSetContactInfectivity = true;
	}
	if(msg.port() == inTotalPopulation) {
		totalPopulation = x;
		isSetTotalPopulation = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusInfected::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusInfected::outputFunction(const CollectMessage &msg)
{
	if( isSetInfected && isSetSusceptible && isSetContactInfectivity && isSetTotalPopulation ) {
		double val = (infected * susceptible) / (contactInfectivity * totalPopulation);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}