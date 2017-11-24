#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPreviousConsumptionIntegrator.h"

using namespace std;

FtotPreviousConsumptionIntegrator::FtotPreviousConsumptionIntegrator(const string &name) :
	inPlus_ChgPreviousConsumption(addInputPort("inPlus_ChgPreviousConsumption")),
	out(addOutputPort("out")),
	val_inPlus_ChgPreviousConsumption(0),
	isSet_val_inPlus_ChgPreviousConsumption(false),
	Atomic(name)
{
}


Model &FtotPreviousConsumptionIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPreviousConsumptionIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_ChgPreviousConsumption) {
		val_inPlus_ChgPreviousConsumption = x;
		isSet_val_inPlus_ChgPreviousConsumption = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPreviousConsumptionIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPreviousConsumptionIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_ChgPreviousConsumption ) {
		plus = plus + val_inPlus_ChgPreviousConsumption;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}