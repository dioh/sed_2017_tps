#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxinvestmentFunctionReal.h"

using namespace std;

AuxinvestmentFunctionReal::AuxinvestmentFunctionReal(const string &name) :
	Atomic(name),
	in_piR(addInputPort("in_piR")),
	in_piS(addInputPort("in_piS")),
	in_piZ(addInputPort("in_piZ")),
	isSet_piR(false),
	isSet_piS(false),
	isSet_piZ(false),
	out(addOutputPort("out"))
{
}


Model &AuxinvestmentFunctionReal::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxinvestmentFunctionReal::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_piR) {
		piR = x;
		isSet_piR = true;
	}
	if(msg.port() == in_piS) {
		piS = x;
		isSet_piS = true;
	}
	if(msg.port() == in_piZ) {
		piZ = x;
		isSet_piZ = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxinvestmentFunctionReal::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxinvestmentFunctionReal::outputFunction(const CollectMessage &msg)
{
	if( isSet_piR & isSet_piS & isSet_piZ ) {
		double val = (piR - piZ) * piS;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}