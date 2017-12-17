#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvestmentFunctionReal.h"

using namespace std;

InvestmentFunctionReal::InvestmentFunctionReal(const string &name) :
	Atomic(name),
	in_piR(addInputPort("in_piR")),
	in_piZ(addInputPort("in_piZ")),
	in_piS(addInputPort("in_piS")),
	isSet_piR(false),
	isSet_piZ(false),
	isSet_piS(false),
	out(addOutputPort("out"))
{
}


Model &InvestmentFunctionReal::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvestmentFunctionReal::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_piR) {
		piR = x;
		isSet_piR = true;
	}
	if(msg.port() == in_piZ) {
		piZ = x;
		isSet_piZ = true;
	}
	if(msg.port() == in_piS) {
		piS = x;
		isSet_piS = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvestmentFunctionReal::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvestmentFunctionReal::outputFunction(const CollectMessage &msg)
{
	if( isSet_piR & isSet_piZ & isSet_piS ) {
		double val = (piR - piZ) * piS;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}