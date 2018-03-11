#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PiIG.h"

using namespace std;

PiIG::PiIG(const string &name) :
	Atomic(name),
	YIValue(addInputPort("YIValue")),
	WagesI(addInputPort("WagesI")),
	isSet_val_YIValue(false),
	isSet_val_WagesI(false),
	out(addOutputPort("out"))
{
}


Model &PiIG::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PiIG::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == YIValue) {
		val_YIValue = x;
		isSet_val_YIValue = true;
	}
	if(msg.port() == WagesI) {
		val_WagesI = x;
		isSet_val_WagesI = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PiIG::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PiIG::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_YIValue & isSet_val_WagesI ) {
		double val = (val_YIValue-val_WagesI);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}