#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Fminus.h"

using namespace std;

Fminus::Fminus(const string &name) :
	Atomic(name),
	inVar1(addInputPort("inVar1")),
	inVar2(addInputPort("inVar2")),
	out(addOutputPort("out")),
	var1(1),
	var2(1),
	val(1)
{
}


Model &Fminus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Fminus::externalFunction(const ExternalMessage &msg)
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


Model &Fminus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Fminus::outputFunction(const CollectMessage &msg)
{
	double characteristic_time = 100;
	double room_temperature = 70;
	val = (var1 - room_temperature) / characteristic_time;

	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out, out_value);

	return *this ;
}
