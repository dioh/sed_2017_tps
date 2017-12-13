#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusInvestmentinflow.h"

using namespace std;

FplusInvestmentinflow::FplusInvestmentinflow(const string &name) :
	Atomic(name),
	in_constant(addInputPort("in_constant")),
	isSet_constant(false),
	out(addOutputPort("out"))
{
}


Model &FplusInvestmentinflow::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusInvestmentinflow::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_constant) {
		constant = x;
		isSet_constant = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusInvestmentinflow::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusInvestmentinflow::outputFunction(const CollectMessage &msg)
{
	if( isSet_constant ) {
		double val = constant;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}