#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPredatorIntegrator.h"

using namespace std;

FtotPredatorIntegrator::FtotPredatorIntegrator(const string &name) :
	inMinus_MinusPredator(addInputPort("inMinus_MinusPredator")),
	inPlus_PlusPredator(addInputPort("inPlus_PlusPredator")),
	out(addOutputPort("out")),
	val_inMinus_MinusPredator(0),
	val_inPlus_PlusPredator(0),
	isSet_val_inMinus_MinusPredator(false),
	isSet_val_inPlus_PlusPredator(false),
	Atomic(name)
{
}


Model &FtotPredatorIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPredatorIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_MinusPredator) {
		val_inMinus_MinusPredator = x;
		isSet_val_inMinus_MinusPredator = true;
	}
	if(msg.port() == inPlus_PlusPredator) {
		val_inPlus_PlusPredator = x;
		isSet_val_inPlus_PlusPredator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPredatorIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPredatorIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_MinusPredator & isSet_val_inPlus_PlusPredator ) {
		minus = minus + val_inMinus_MinusPredator;
		plus = plus + val_inPlus_PlusPredator;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}