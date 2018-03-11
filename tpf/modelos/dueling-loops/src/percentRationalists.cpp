#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "percentRationalists.h"

using namespace std;

percentRationalists::percentRationalists(const string &name) :
	Atomic(name),
	RationalSupporters(addInputPort("RationalSupporters")),
	RationalSupporters(addInputPort("RationalSupporters")),
	Degenerates(addInputPort("Degenerates")),
	isSet_val_RationalSupporters(false),
	isSet_val_RationalSupporters(false),
	isSet_val_Degenerates(false),
	out(addOutputPort("out"))
{
}


Model &percentRationalists::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &percentRationalists::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == RationalSupporters) {
		val_RationalSupporters = x;
		isSet_val_RationalSupporters = true;
	}
	if(msg.port() == RationalSupporters) {
		val_RationalSupporters = x;
		isSet_val_RationalSupporters = true;
	}
	if(msg.port() == Degenerates) {
		val_Degenerates = x;
		isSet_val_Degenerates = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &percentRationalists::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &percentRationalists::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_RationalSupporters & isSet_val_RationalSupporters & isSet_val_Degenerates ) {
		double val = val_val_RationalSupporters / ( val_val_RationalSupporters + val_Degenerates );
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}