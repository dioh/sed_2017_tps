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
	isSet_preyIntegrator(false),
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
	if( isSet_preyIntegrator ) {
		double val = 0.1 * preyIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}