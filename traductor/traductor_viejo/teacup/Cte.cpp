#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Cte.h"

using namespace std;

Cte::Cte(const string &name) :
	Atomic(name),
	inVal(addInputPort("inVal")),
	out(addOutputPort("out"))
{
}


Model &Cte::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Cte::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
	if(msg.port() == inVal) {
		val = x;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Cte::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Cte::outputFunction(const CollectMessage &msg)
{
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out, out_value);
	return *this ;
}
