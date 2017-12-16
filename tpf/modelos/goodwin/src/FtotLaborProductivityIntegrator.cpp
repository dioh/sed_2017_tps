#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotLaborProductivityIntegrator.h"

using namespace std;

FtotLaborProductivityIntegrator::FtotLaborProductivityIntegrator(const string &name) :
	inPlus_chgLaborProductivity(addInputPort("inPlus_chgLaborProductivity")),
	out(addOutputPort("out")),
	val_inPlus_chgLaborProductivity(0),
	isSet_val_inPlus_chgLaborProductivity(false),
	Atomic(name)
{
}


Model &FtotLaborProductivityIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotLaborProductivityIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgLaborProductivity) {
		val_inPlus_chgLaborProductivity = x;
		isSet_val_inPlus_chgLaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotLaborProductivityIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotLaborProductivityIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgLaborProductivity ) {
		plus = plus + val_inPlus_chgLaborProductivity;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}