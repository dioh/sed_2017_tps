#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotInvestmentIntegrator.h"

using namespace std;

FtotInvestmentIntegrator::FtotInvestmentIntegrator(const string &name) :
	inPlus_inflow(addInputPort("inPlus_inflow")),
	out(addOutputPort("out")),
	val_inPlus_inflow(0),
	isSet_val_inPlus_inflow(false),
	Atomic(name)
{
}


Model &FtotInvestmentIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotInvestmentIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_inflow) {
		val_inPlus_inflow = x;
		isSet_val_inPlus_inflow = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotInvestmentIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotInvestmentIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_inflow ) {
		plus = plus + val_inPlus_inflow;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}