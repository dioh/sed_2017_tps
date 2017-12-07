#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusCapitalbiflow.h"

using namespace std;

FminusCapitalbiflow::FminusCapitalbiflow(const string &name) :
	Atomic(name),
	in_investmentIntegrator(addInputPort("in_investmentIntegrator")),
	in_capitalIntegrator(addInputPort("in_capitalIntegrator")),
	isSet_investmentIntegrator(false),
	isSet_capitalIntegrator(false),
	out(addOutputPort("out"))
{
}


Model &FminusCapitalbiflow::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusCapitalbiflow::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_investmentIntegrator) {
		investmentIntegrator = x;
		isSet_investmentIntegrator = true;
	}
	if(msg.port() == in_capitalIntegrator) {
		capitalIntegrator = x;
		isSet_capitalIntegrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusCapitalbiflow::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusCapitalbiflow::outputFunction(const CollectMessage &msg)
{
	if( isSet_investmentIntegrator & isSet_capitalIntegrator ) {
		double val = capitalIntegrator - investmentIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}