#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TemperatureTot.h"

using namespace std;

TemperatureTot::TemperatureTot(const string &name) :
	Atomic(name),
	out(addOutputPort("out"))
{
}


Model &TemperatureTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TemperatureTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TemperatureTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TemperatureTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if() {
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}