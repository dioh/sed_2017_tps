#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FminusHares.h"

using namespace std;

FminusHares::FminusHares(const string &name) :
	Atomic(name),
	inHares(addInputPort("inHares")),
	inLynx(addInputPort("inLynx")),
	inHareDeathRate(addInputPort("inHareDeathRate")),
	isSetHares(false),
	isSetLynx(false),
	isSetHareDeathRate(false),
	out(addOutputPort("out"))
{
}


Model &FminusHares::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FminusHares::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inHares) {
		hares = x;
		isSetHares = true;
	}
	if(msg.port() == inLynx) {
		lynx = x;
		isSetLynx = true;
	}
	if(msg.port() == inHareDeathRate) {
		hareDeathRate = x;
		isSetHareDeathRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FminusHares::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FminusHares::outputFunction(const CollectMessage &msg)
{
	if( isSetHares && isSetLynx && isSetHareDeathRate ) {
		double val = hareDeathRate * hares * lynx;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}