#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Lend.h"

using namespace std;

Lend::Lend(const string &name) :
	Atomic(name),
	DepCons(addInputPort("DepCons")),
	tauL(addInputPort("tauL")),
	isSet_val_DepCons(false),
	isSet_val_tauL(false),
	out(addOutputPort("out"))
{
}


Model &Lend::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Lend::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == DepCons) {
		val_DepCons = x;
		isSet_val_DepCons = true;
	}
	if(msg.port() == tauL) {
		val_tauL = x;
		isSet_val_tauL = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Lend::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Lend::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_DepCons & isSet_val_tauL ) {
		double val = (val_DepCons/val_tauL);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}