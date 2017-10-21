#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusLynx.h"

using namespace std;

FplusLynx::FplusLynx(const string &name) :
	Atomic(name),
	inLynx(addInputPort("inLynx")),
	inHares(addInputPort("inHares")),
	inLynxBirthRate(addInputPort("inLynxBirthRate")),
	isSetLynx(false),
	isSetHares(false),
	isSetLynxBirthRate(false),
	out(addOutputPort("out"))
{
}


Model &FplusLynx::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusLynx::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inLynx) {
		lynx = x;
		isSetLynx = true;
	}
	if(msg.port() == inHares) {
		hares = x;
		isSetHares = true;
	}
	if(msg.port() == inLynxBirthRate) {
		lynxBirthRate = x;
		isSetLynxBirthRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusLynx::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusLynx::outputFunction(const CollectMessage &msg)
{
	if( isSetLynx && isSetHares && isSetLynxBirthRate ) {
		double val = lynxBirthRate * lynx * hares;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}