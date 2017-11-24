#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotStock1Integrator.h"

using namespace std;

FtotStock1Integrator::FtotStock1Integrator(const string &name) :
	inPlus_Flow1(addInputPort("inPlus_Flow1")),
	out(addOutputPort("out")),
	val_inPlus_Flow1(0),
	isSet_val_inPlus_Flow1(false),
	Atomic(name)
{
}


Model &FtotStock1Integrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotStock1Integrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_Flow1) {
		val_inPlus_Flow1 = x;
		isSet_val_inPlus_Flow1 = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotStock1Integrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotStock1Integrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_Flow1 ) {
		plus = plus + val_inPlus_Flow1;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}