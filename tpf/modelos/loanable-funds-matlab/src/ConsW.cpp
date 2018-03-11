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
	tauWC(addInputPort("tauWC")),
	isSet_val_Workers(false),
	isSet_val_tauWC(false),
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
	if(msg.port() == tauWC) {
		val_tauWC = x;
		isSet_val_tauWC = true;
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
	if( isSet_val_Workers & isSet_val_tauWC ) {
		double val = (val_Workers/val_tauWC);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}