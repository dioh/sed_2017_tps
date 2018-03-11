#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "YCValue.h"

using namespace std;

YCValue::YCValue(const string &name) :
	Atomic(name),
	DepCons(addInputPort("DepCons")),
	tauMC(addInputPort("tauMC")),
	isSet_val_DepCons(false),
	isSet_val_tauMC(false),
	out(addOutputPort("out"))
{
}


Model &YCValue::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &YCValue::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == DepCons) {
		val_DepCons = x;
		isSet_val_DepCons = true;
	}
	if(msg.port() == tauMC) {
		val_tauMC = x;
		isSet_val_tauMC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &YCValue::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &YCValue::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_DepCons & isSet_val_tauMC ) {
		double val = (val_DepCons/val_tauMC);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}