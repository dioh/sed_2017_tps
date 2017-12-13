#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPreyIntegrator.h"

using namespace std;

FtotPreyIntegrator::FtotPreyIntegrator(const string &name) :
	inMinus_MinusPrey(addInputPort("inMinus_MinusPrey")),
	inPlus_PlusPrey(addInputPort("inPlus_PlusPrey")),
	out(addOutputPort("out")),
	val_inMinus_MinusPrey(0),
	val_inPlus_PlusPrey(0),
	isSet_val_inMinus_MinusPrey(false),
	isSet_val_inPlus_PlusPrey(false),
	Atomic(name)
{
}


Model &FtotPreyIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPreyIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_MinusPrey) {
		val_inMinus_MinusPrey = x;
		isSet_val_inMinus_MinusPrey = true;
	}
	if(msg.port() == inPlus_PlusPrey) {
		val_inPlus_PlusPrey = x;
		isSet_val_inPlus_PlusPrey = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPreyIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPreyIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_MinusPrey & isSet_val_inPlus_PlusPrey ) {
		minus = minus + val_inMinus_MinusPrey;
		plus = plus + val_inPlus_PlusPrey;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}