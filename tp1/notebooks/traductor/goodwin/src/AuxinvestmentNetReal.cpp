#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxinvestmentNetReal.h"

using namespace std;

AuxinvestmentNetReal::AuxinvestmentNetReal(const string &name) :
	Atomic(name),
	in_investmentGross(addInputPort("in_investmentGross")),
	in_deltaKReal(addInputPort("in_deltaKReal")),
	in_capitalIntegrator(addInputPort("in_capitalIntegrator")),
	isSet_investmentGross(false),
	isSet_deltaKReal(false),
	isSet_capitalIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &AuxinvestmentNetReal::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxinvestmentNetReal::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_investmentGross) {
		investmentGross = x;
		isSet_investmentGross = true;
	}
	if(msg.port() == in_deltaKReal) {
		deltaKReal = x;
		isSet_deltaKReal = true;
	}
	if(msg.port() == in_capitalIntegrator) {
		capitalIntegrator = x;
		isSet_capitalIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxinvestmentNetReal::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxinvestmentNetReal::outputFunction(const CollectMessage &msg)
{
	if( isSet_investmentGross & isSet_deltaKReal & isSet_capitalIntegrator ) {
		double val = investmentGross - (capitalIntegrator * deltaKReal);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}