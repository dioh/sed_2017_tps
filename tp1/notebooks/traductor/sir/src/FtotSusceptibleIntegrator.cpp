#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotSusceptibleIntegrator.h"

using namespace std;

FtotSusceptibleIntegrator::FtotSusceptibleIntegrator(const string &name) :
	inMinus_Succumbing(addInputPort("inMinus_Succumbing")),
	out(addOutputPort("out")),
	val_inMinus_Succumbing(0),
	isSet_val_inMinus_Succumbing(false),
	Atomic(name)
{
}


Model &FtotSusceptibleIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotSusceptibleIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_Succumbing) {
		val_inMinus_Succumbing = x;
		isSet_val_inMinus_Succumbing = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotSusceptibleIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotSusceptibleIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_Succumbing ) {
		minus = minus + val_inMinus_Succumbing;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}