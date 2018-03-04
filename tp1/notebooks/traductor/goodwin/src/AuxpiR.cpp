#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxpiR.h"

using namespace std;

AuxpiR::AuxpiR(const string &name) :
	Atomic(name),
	in_capitalIntegrator(addInputPort("in_capitalIntegrator")),
	in_profitNet(addInputPort("in_profitNet")),
	isSet_capitalIntegrator(false),
	isSet_profitNet(false),
	out(addOutputPort("out"))
{
}


Model &AuxpiR::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxpiR::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_capitalIntegrator) {
		capitalIntegrator = x;
		isSet_capitalIntegrator = true;
	}
	if(msg.port() == in_profitNet) {
		profitNet = x;
		isSet_profitNet = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxpiR::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxpiR::outputFunction(const CollectMessage &msg)
{
	if( isSet_capitalIntegrator & isSet_profitNet ) {
		double val = profitNet / capitalIntegrator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}