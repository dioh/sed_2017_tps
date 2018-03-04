#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPreyPlusPrey.h"

using namespace std;

FplusPreyPlusPrey::FplusPreyPlusPrey(const string &name) :
	Atomic(name),
	in_preyIntegrator(addInputPort("in_preyIntegrator")),
	in_paramA(addInputPort("in_paramA")),
	isSet_preyIntegrator(false),
	isSet_paramA(false),
	out(addOutputPort("out"))
{
}


Model &FplusPreyPlusPrey::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPreyPlusPrey::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_preyIntegrator) {
		preyIntegrator = x;
		isSet_preyIntegrator = true;
	}
	if(msg.port() == in_paramA) {
		paramA = x;
		isSet_paramA = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPreyPlusPrey::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPreyPlusPrey::outputFunction(const CollectMessage &msg)
{
	if( isSet_preyIntegrator & isSet_paramA ) {
		double val = paramA * preyIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}