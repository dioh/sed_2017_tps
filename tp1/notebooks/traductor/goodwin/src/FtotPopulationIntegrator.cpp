#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPopulationIntegrator.h"

using namespace std;

FtotPopulationIntegrator::FtotPopulationIntegrator(const string &name) :
	inPlus_chgPopulation(addInputPort("inPlus_chgPopulation")),
	out(addOutputPort("out")),
	val_inPlus_chgPopulation(0),
	isSet_val_inPlus_chgPopulation(false),
	Atomic(name)
{
}


Model &FtotPopulationIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPopulationIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgPopulation) {
		val_inPlus_chgPopulation = x;
		isSet_val_inPlus_chgPopulation = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPopulationIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPopulationIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgPopulation ) {
		plus = plus + val_inPlus_chgPopulation;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}