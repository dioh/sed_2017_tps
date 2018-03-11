#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "YIValue.h"

using namespace std;

YIValue::YIValue(const string &name) :
	Atomic(name),
	DepInv(addInputPort("DepInv")),
	tauMI(addInputPort("tauMI")),
	isSet_val_DepInv(false),
	isSet_val_tauMI(false),
	out(addOutputPort("out"))
{
}


Model &YIValue::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &YIValue::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == DepInv) {
		val_DepInv = x;
		isSet_val_DepInv = true;
	}
	if(msg.port() == tauMI) {
		val_tauMI = x;
		isSet_val_tauMI = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &YIValue::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &YIValue::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_DepInv & isSet_val_tauMI ) {
		double val = (val_DepInv/val_tauMI);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}