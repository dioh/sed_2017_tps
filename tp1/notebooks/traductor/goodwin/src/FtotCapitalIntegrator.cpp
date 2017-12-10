#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotCapitalIntegrator.h"

using namespace std;

FtotCapitalIntegrator::FtotCapitalIntegrator(const string &name) :
	inPlus_chgCapital(addInputPort("inPlus_chgCapital")),
	out(addOutputPort("out")),
	val_inPlus_chgCapital(0),
	isSet_val_inPlus_chgCapital(false),
	Atomic(name)
{
}


Model &FtotCapitalIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotCapitalIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgCapital) {
		val_inPlus_chgCapital = x;
		isSet_val_inPlus_chgCapital = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotCapitalIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotCapitalIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgCapital ) {
		plus = plus + val_inPlus_chgCapital;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}