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
	inHares(addInputPort("inHares")),
	inHareBirthRate(addInputPort("inHareBirthRate")),
	isSetHares(false),
	isSetHareBirthRate(false),
	out(addOutputPort("out"))
{
}


Model &FplusHares::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusHares::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inHares) {
		hares = x;
		isSetHares = true;
	}
	if(msg.port() == inHareBirthRate) {
		hareBirthRate = x;
		isSetHareBirthRate = true;
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
	if( isSetHares && isSetHareBirthRate ) {
		double val = hareBirthRate * hares;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}