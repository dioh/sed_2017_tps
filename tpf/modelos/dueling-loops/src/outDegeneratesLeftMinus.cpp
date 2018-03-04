#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "outDegeneratesLeftMinus.h"

using namespace std;

outDegeneratesLeftMinus::outDegeneratesLeftMinus(const string &name) :
	Atomic(name),
	Degenerates(addInputPort("Degenerates")),
	isSet_val_Degenerates(false),
	out(addOutputPort("out"))
{
}


Model &outDegeneratesLeftMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &outDegeneratesLeftMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Degenerates) {
		val_Degenerates = x;
		isSet_val_Degenerates = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &outDegeneratesLeftMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &outDegeneratesLeftMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Degenerates ) {
		double val = 0.2 *  val_Degenerates;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}