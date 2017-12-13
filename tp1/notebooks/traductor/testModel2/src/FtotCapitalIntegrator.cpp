#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotCapitalIntegrator.h"

using namespace std;

FtotCapitalIntegrator::FtotCapitalIntegrator(const string &name) :
	inPlus_biflow(addInputPort("inPlus_biflow")),
	out(addOutputPort("out")),
	val_inPlus_biflow(0),
	isSet_val_inPlus_biflow(false),
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

	if(msg.port() == inPlus_biflow) {
		val_inPlus_biflow = x;
		isSet_val_inPlus_biflow = true;
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
	if( isSet_val_inPlus_biflow ) {
		plus = plus + val_inPlus_biflow;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}