#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusHares.h"

using namespace std;

FplusHares::FplusHares(const string &name) :
	Atomic(name),
	inVar1(addInputPort("inVar1")),
	inVar2(addInputPort("inVar2")),
	out(addOutputPort("out")),
	var1(1),
	var2(1),
	val(1)
{
}


Model &FplusHares::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusHares::externalFunction(const ExternalMessage &msg)
{
	double f = 0.5;
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inVar1) {
		var1 = x;
	} else if (msg.port() == inVar2) {
		var2 = x;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusHares::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusHares::outputFunction(const CollectMessage &msg)
{
	double hare_birth_rate = 0.4807;
	double val2 = hare_birth_rate * var1;

	Tuple<Real> out_value { val2 };
	sendOutput(msg.time(), out, out_value);

	return *this ;
}
