#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusRecov.h"

using namespace std;

FminusRecov::FminusRecov(const string &name) :
	Atomic(name),
	inVar1(addInputPort("inVar1")),
	inVar2(addInputPort("inVar2")),
	out(addOutputPort("out")),
	var1(1),
	var2(1),
	val(1)
{
}


Model &FminusRecov::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusRecov::externalFunction(const ExternalMessage &msg)
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


Model &FminusRecov::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusRecov::outputFunction(const CollectMessage &msg)
{
	return *this ;
}
