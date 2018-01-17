#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "MinusPredatorPlus.h"

using namespace std;

MinusPredatorPlus::MinusPredatorPlus(const string &name) :
	Atomic(name),
	paramC(addInputPort("paramC")),
	Predator(addInputPort("Predator")),
	isSet_val_paramC(false),
	isSet_val_Predator(false),
	out(addOutputPort("out"))
{
}


Model &MinusPredatorPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &MinusPredatorPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == paramC) {
		val_paramC = x;
		isSet_val_paramC = true;
	}
	if(msg.port() == Predator) {
		val_Predator = x;
		isSet_val_Predator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &MinusPredatorPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &MinusPredatorPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_paramC & isSet_val_Predator ) {
		double val = val_paramC * val_Predator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}