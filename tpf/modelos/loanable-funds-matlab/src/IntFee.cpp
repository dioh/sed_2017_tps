#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "IntFee.h"

using namespace std;

IntFee::IntFee(const string &name) :
	Atomic(name),
	Interest(addInputPort("Interest")),
	bfValue(addInputPort("bfValue")),
	isSet_val_Interest(false),
	isSet_val_bfValue(false),
	out(addOutputPort("out"))
{
}


Model &IntFee::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &IntFee::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	if(msg.port() == bfValue) {
		val_bfValue = x;
		isSet_val_bfValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &IntFee::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &IntFee::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Interest & isSet_val_bfValue ) {
		double val = (val_Interest*val_bfValue);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}