#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPreviousOutputIntegrator.h"

using namespace std;

FtotPreviousOutputIntegrator::FtotPreviousOutputIntegrator(const string &name) :
	inPlus_ChgPreviousOutput(addInputPort("inPlus_ChgPreviousOutput")),
	out(addOutputPort("out")),
	val_inPlus_ChgPreviousOutput(0),
	isSet_val_inPlus_ChgPreviousOutput(false),
	Atomic(name)
{
}


Model &FtotPreviousOutputIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPreviousOutputIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_ChgPreviousOutput) {
		val_inPlus_ChgPreviousOutput = x;
		isSet_val_inPlus_ChgPreviousOutput = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPreviousOutputIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPreviousOutputIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_ChgPreviousOutput ) {
		plus = plus + val_inPlus_ChgPreviousOutput;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}