#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "MinusPreyPlus.h"

using namespace std;

MinusPreyPlus::MinusPreyPlus(const string &name) :
	Atomic(name),
	paramB(addInputPort("paramB")),
	Prey(addInputPort("Prey")),
	Predator(addInputPort("Predator")),
	isSet_val_paramB(false),
	isSet_val_Prey(false),
	isSet_val_Predator(false),
	out(addOutputPort("out"))
{
}


Model &MinusPreyPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &MinusPreyPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == paramB) {
		val_paramB = x;
		isSet_val_paramB = true;
	}
	if(msg.port() == Prey) {
		val_Prey = x;
		isSet_val_Prey = true;
	}
	if(msg.port() == Predator) {
		val_Predator = x;
		isSet_val_Predator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &MinusPreyPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &MinusPreyPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_paramB & isSet_val_Prey & isSet_val_Predator ) {
		double val = val_paramB * val_Prey * val_Predator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}