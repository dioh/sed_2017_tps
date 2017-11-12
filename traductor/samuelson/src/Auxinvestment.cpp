#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxinvestment.h"

using namespace std;

Auxinvestment::Auxinvestment(const string &name) :
	Atomic(name),
	in_previousconsumptionIntegrator(addInputPort("in_previousconsumptionIntegrator")),
	in_investmentproportionalityrelationbeta(addInputPort("in_investmentproportionalityrelationbeta")),
	in_consumption(addInputPort("in_consumption")),
	isSet_previousconsumptionIntegrator(false),
	isSet_investmentproportionalityrelationbeta(false),
	isSet_consumption(false),
	out(addOutputPort("out"))
{
}


Model &Auxinvestment::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxinvestment::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_previousconsumptionIntegrator) {
		previousconsumptionIntegrator = x;
		isSet_previousconsumptionIntegrator = true;
	}
	if(msg.port() == in_investmentproportionalityrelationbeta) {
		investmentproportionalityrelationbeta = x;
		isSet_investmentproportionalityrelationbeta = true;
	}
	if(msg.port() == in_consumption) {
		consumption = x;
		isSet_consumption = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxinvestment::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxinvestment::outputFunction(const CollectMessage &msg)
{
	if( isSet_previousconsumptionIntegrator & isSet_investmentproportionalityrelationbeta & isSet_consumption ) {
		double val = investmentproportionalityrelationbeta * (consumption - previousconsumptionIntegrator);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}