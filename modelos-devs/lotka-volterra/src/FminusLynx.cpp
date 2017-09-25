#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusLynx.h"

using namespace std;

FminusLynx::FminusLynx(const string &name) :
	Atomic(name),
	inVar1(addInputPort("inVar1")),
	inVar2(addInputPort("inVar2")),
	out(addOutputPort("out")),
	var1(1),
	var2(1),
	val(1)
{
}


Model &FminusLynx::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusLynx::externalFunction(const ExternalMessage &msg)
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


Model &FminusLynx::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusLynx::outputFunction(const CollectMessage &msg)
{
	double lynx_death_proportionality_cnst = 0.9272;
	double val2 = lynx_death_proportionality_cnst * var1;

	Tuple<Real> out_value { val2 };
	sendOutput(msg.time(), out, out_value);

	return *this ;
}
