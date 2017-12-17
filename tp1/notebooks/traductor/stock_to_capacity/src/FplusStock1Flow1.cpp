#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusStock1Flow1.h"

using namespace std;

FplusStock1Flow1::FplusStock1Flow1(const string &name) :
	Atomic(name),
	in_growthCoefficient(addInputPort("in_growthCoefficient")),
	in_stock1Integrator(addInputPort("in_stock1Integrator")),
	isSet_growthCoefficient(false),
	isSet_stock1Integrator(false),
	out(addOutputPort("out"))
{
}


Model &FplusStock1Flow1::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusStock1Flow1::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_growthCoefficient) {
		growthCoefficient = x;
		isSet_growthCoefficient = true;
	}
	if(msg.port() == in_stock1Integrator) {
		stock1Integrator = x;
		isSet_stock1Integrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusStock1Flow1::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusStock1Flow1::outputFunction(const CollectMessage &msg)
{
	if( isSet_growthCoefficient & isSet_stock1Integrator ) {
		double val = growthCoefficient * stock1Integrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}