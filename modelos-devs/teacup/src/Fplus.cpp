#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Fplus.h"

using namespace std;

Fplus::Fplus(const string &name) :
	Atomic(name),
	inVar1(addInputPort("inVar1")),
	inVar2(addInputPort("inVar2")),
	out(addOutputPort("out")),
	var1(1),
	var2(1),
	val(1)
{
}


Model &Fplus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Fplus::externalFunction(const ExternalMessage &msg)
{
	double f = 0.5;
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inVar1) {
		var1 = x;
	} else if (msg.port() == inVar2) {
		var2 = x;
	}
	val = 1 * x;
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Fplus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Fplus::outputFunction(const CollectMessage &msg)
{
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out, out_value);

	return *this ;
}
