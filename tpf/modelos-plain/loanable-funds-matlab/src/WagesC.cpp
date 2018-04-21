#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WagesC.h"

using namespace std;

WagesC::WagesC(const string &name) :
	Atomic(name),
	YCValue(addInputPort("YCValue")),
	wSValue(addInputPort("wSValue")),
	isSet_val_YCValue(false),
	isSet_val_wSValue(false),
	out(addOutputPort("out"))
{
}


Model &WagesC::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WagesC::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == YCValue) {
		val_YCValue = x;
		isSet_val_YCValue = true;
	}
	if(msg.port() == wSValue) {
		val_wSValue = x;
		isSet_val_wSValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WagesC::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WagesC::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_YCValue & isSet_val_wSValue ) {
		double val = (val_YCValue*val_wSValue);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}