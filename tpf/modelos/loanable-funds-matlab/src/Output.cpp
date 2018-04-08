#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Output.h"

using namespace std;

Output::Output(const string &name) :
	Atomic(name),
	YCValue(addInputPort("YCValue")),
	YIValue(addInputPort("YIValue")),
	isSet_val_YCValue(false),
	isSet_val_YIValue(false),
	out(addOutputPort("out"))
{
}


Model &Output::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Output::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == YCValue) {
		val_YCValue = x;
		isSet_val_YCValue = true;
	}
	if(msg.port() == YIValue) {
		val_YIValue = x;
		isSet_val_YIValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Output::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Output::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_YCValue & isSet_val_YIValue ) {
		double val = (val_YCValue+val_YIValue);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}