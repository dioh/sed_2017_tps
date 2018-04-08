#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConsW.h"

using namespace std;

ConsW::ConsW(const string &name) :
	Atomic(name),
	Workers(addInputPort("Workers")),
	tauWVal(addInputPort("tauWVal")),
	isSet_val_Workers(false),
	isSet_val_tauWVal(false),
	out(addOutputPort("out"))
{
}


Model &ConsW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConsW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Workers) {
		val_Workers = x;
		isSet_val_Workers = true;
	}
	if(msg.port() == tauWVal) {
		val_tauWVal = x;
		isSet_val_tauWVal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConsW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConsW::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Workers & isSet_val_tauWVal ) {
		double val = (val_Workers/val_tauWVal);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}