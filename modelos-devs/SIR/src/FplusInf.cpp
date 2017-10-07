#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusInf.h"

using namespace std;

FplusInf::FplusInf(const string &name) :
	Atomic(name),
	inInfected(addInputPort("inInfected")),
	inSusceptible(addInputPort("inSusceptible")),
	inContactInfectivity(addInputPort("inContactInfectivity")),
	inTotalPopulation(addInputPort("inTotalPopulation")),
	out(addOutputPort("out")),
	isSetInfected(false),
	isSetSusceptible(false),
	isSetContactInfectivity(false),
	isSetTotalPopulation(false)
{
}


Model &FplusInf::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusInf::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inInfected) {
		infected = x;
		isSetInfected = true;
	} else if (msg.port() == inSusceptible) {
		susceptible = x;
		isSetSusceptible = true;
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


Model &FplusInf::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusInf::outputFunction(const CollectMessage &msg)
{
	if(isSetSusceptible && isSetInfected && isSetContactInfectivity && isSetTotalPopulation) {
		double val = (infected * susceptible) / (contactInfectivity * totalPopulation);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}
