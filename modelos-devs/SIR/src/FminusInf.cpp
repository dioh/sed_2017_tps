#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusInf.h"

using namespace std;

FminusInf::FminusInf(const string &name) :
	Atomic(name),
	inInfected(addInputPort("inInfected")),
	inDuration(addInputPort("inDuration")),
	out(addOutputPort("out")),
	isSetInfected(false),
	isSetDuration(false)
{
}


Model &FminusInf::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusInf::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inInfected) {
		infected = x;
		isSetInfected = true;
	} else if (msg.port() == inDuration) {
		duration = x;
		isSetDuration = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusInf::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusInf::outputFunction(const CollectMessage &msg)
{
	if(isSetDuration && isSetInfected) {
		double val = infected / duration;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}
