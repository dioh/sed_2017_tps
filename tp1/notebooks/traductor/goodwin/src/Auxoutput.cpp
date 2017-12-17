#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxoutput.h"

using namespace std;

Auxoutput::Auxoutput(const string &name) :
	Atomic(name),
	in_capitalIntegrator(addInputPort("in_capitalIntegrator")),
	in_velocityOfMoney(addInputPort("in_velocityOfMoney")),
	isSet_capitalIntegrator(false),
	isSet_velocityOfMoney(false),
	out(addOutputPort("out"))
{
}


Model &Auxoutput::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxoutput::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_capitalIntegrator) {
		capitalIntegrator = x;
		isSet_capitalIntegrator = true;
	}
	if(msg.port() == in_velocityOfMoney) {
		velocityOfMoney = x;
		isSet_velocityOfMoney = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxoutput::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxoutput::outputFunction(const CollectMessage &msg)
{
	if( isSet_capitalIntegrator & isSet_velocityOfMoney ) {
		double val = capitalIntegrator / velocityOfMoney;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}