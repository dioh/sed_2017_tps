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
	in_prevConsIntegrator(addInputPort("in_prevConsIntegrator")),
	in_investmentproportionalityrelationbeta(addInputPort("in_investmentproportionalityrelationbeta")),
	in_consumption(addInputPort("in_consumption")),
	isSet_prevConsIntegrator(false),
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

	if(msg.port() == in_prevConsIntegrator) {
		prevConsIntegrator = x;
		isSet_prevConsIntegrator = true;
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
	if( isSet_prevConsIntegrator & isSet_investmentproportionalityrelationbeta & isSet_consumption ) {
		double val = investmentproportionalityrelationbeta * (consumption - prevConsIntegrator);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}