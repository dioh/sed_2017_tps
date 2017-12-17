#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotRecoveredIntegrator.h"

using namespace std;

FtotRecoveredIntegrator::FtotRecoveredIntegrator(const string &name) :
	inPlus_Recovering(addInputPort("inPlus_Recovering")),
	out(addOutputPort("out")),
	val_inPlus_Recovering(0),
	isSet_val_inPlus_Recovering(false),
	Atomic(name)
{
}


Model &FtotRecoveredIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotRecoveredIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_Recovering) {
		val_inPlus_Recovering = x;
		isSet_val_inPlus_Recovering = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotRecoveredIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotRecoveredIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_Recovering ) {
		plus = plus + val_inPlus_Recovering;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}