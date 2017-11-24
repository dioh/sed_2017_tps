#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPrevConsIntegrator.h"

using namespace std;

FtotPrevConsIntegrator::FtotPrevConsIntegrator(const string &name) :
	inPlus_ChgPrevCons(addInputPort("inPlus_ChgPrevCons")),
	out(addOutputPort("out")),
	val_inPlus_ChgPrevCons(0),
	isSet_val_inPlus_ChgPrevCons(false),
	Atomic(name)
{
}


Model &FtotPrevConsIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPrevConsIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_ChgPrevCons) {
		val_inPlus_ChgPrevCons = x;
		isSet_val_inPlus_ChgPrevCons = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPrevConsIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPrevConsIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_ChgPrevCons ) {
		plus = plus + val_inPlus_ChgPrevCons;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}