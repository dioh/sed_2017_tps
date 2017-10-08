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
	inLynx(addInputPort("inLynx")),
	inLynxDeathRate(addInputPort("inLynxDeathRate")),
	isSetLynx(false),
	isSetLynxDeathRate(false),
	out(addOutputPort("out"))
{
}


Model &FminusLynx::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusLynx::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inLynx) {
		lynx = x;
		isSetLynx = true;
	}
	if(msg.port() == inLynxDeathRate) {
		lynxDeathRate = x;
		isSetLynxDeathRate = true;
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
	if( isSetLynx && isSetLynxDeathRate ) {
		double val = lynxDeathRate * lynx;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}