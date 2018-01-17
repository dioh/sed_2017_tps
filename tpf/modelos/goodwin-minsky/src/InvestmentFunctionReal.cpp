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
	piR(addInputPort("piR")),
	piZ(addInputPort("piZ")),
	piS(addInputPort("piS")),
	isSet_val_piR(false),
	isSet_val_piZ(false),
	isSet_val_piS(false),
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

	if(msg.port() == piR) {
		val_piR = x;
		isSet_val_piR = true;
	}
	if(msg.port() == piZ) {
		val_piZ = x;
		isSet_val_piZ = true;
	}
	if(msg.port() == piS) {
		val_piS = x;
		isSet_val_piS = true;
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
	if( isSet_val_piR & isSet_val_piZ & isSet_val_piS ) {
		double val = (val_piR - val_piZ) * val_piS;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}