#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotInfectiousIntegrator.h"

using namespace std;

FtotInfectiousIntegrator::FtotInfectiousIntegrator(const string &name) :
	inMinus_Recovering(addInputPort("inMinus_Recovering")),
	inPlus_Succumbing(addInputPort("inPlus_Succumbing")),
	out(addOutputPort("out")),
	val_inMinus_Recovering(0),
	val_inPlus_Succumbing(0),
	isSet_val_inMinus_Recovering(false),
	isSet_val_inPlus_Succumbing(false),
	Atomic(name)
{
}


Model &FtotInfectiousIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotInfectiousIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_Recovering) {
		val_inMinus_Recovering = x;
		isSet_val_inMinus_Recovering = true;
	}
	if(msg.port() == inPlus_Succumbing) {
		val_inPlus_Succumbing = x;
		isSet_val_inPlus_Succumbing = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotInfectiousIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotInfectiousIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_Recovering & isSet_val_inPlus_Succumbing ) {
		minus = minus + val_inMinus_Recovering;
		plus = plus + val_inPlus_Succumbing;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}