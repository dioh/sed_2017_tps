#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotHares.h"

using namespace std;

FtotHares::FtotHares(const string &name) :
	Atomic(name),
	inPlus(addInputPort("inPlus")),
	inMinus(addInputPort("inMinus")),
	out(addOutputPort("out")),
	plus(0),
	minus(0)
{
}


Model &FtotHares::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotHares::externalFunction(const ExternalMessage &msg)
{
	double f = 0.5;
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus) {
		plus = x;
	} else if (msg.port() == inMinus) {
		minus = x;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotHares::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotHares::outputFunction(const CollectMessage &msg)
{
	double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out, out_value);

	return *this ;
}
