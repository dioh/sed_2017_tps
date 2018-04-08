#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WagesI.h"

using namespace std;

WagesI::WagesI(const string &name) :
	Atomic(name),
	YIValue(addInputPort("YIValue")),
	wSValue(addInputPort("wSValue")),
	isSet_val_YIValue(false),
	isSet_val_wSValue(false),
	out(addOutputPort("out"))
{
}


Model &WagesI::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WagesI::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == YIValue) {
		val_YIValue = x;
		isSet_val_YIValue = true;
	}
	if(msg.port() == wSValue) {
		val_wSValue = x;
		isSet_val_wSValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WagesI::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WagesI::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_YIValue & isSet_val_wSValue ) {
		double val = (val_YIValue*val_wSValue);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}