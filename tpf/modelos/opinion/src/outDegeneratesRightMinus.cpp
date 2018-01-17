#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "outDegeneratesRightMinus.h"

using namespace std;

outDegeneratesRightMinus::outDegeneratesRightMinus(const string &name) :
	Atomic(name),
	Degenerates(addInputPort("Degenerates")),
	isSet_val_Degenerates(false),
	out(addOutputPort("out"))
{
}


Model &outDegeneratesRightMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &outDegeneratesRightMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Degenerates) {
		val_Degenerates = x;
		isSet_val_Degenerates = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &outDegeneratesRightMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &outDegeneratesRightMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Degenerates ) {
		double val = 0.1 * val_Degenerates;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}