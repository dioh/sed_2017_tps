#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PlusPreyPlus.h"

using namespace std;

PlusPreyPlus::PlusPreyPlus(const string &name) :
	Atomic(name),
	paramA(addInputPort("paramA")),
	Prey(addInputPort("Prey")),
	isSet_val_paramA(false),
	isSet_val_Prey(false),
	out(addOutputPort("out"))
{
}


Model &PlusPreyPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PlusPreyPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == paramA) {
		val_paramA = x;
		isSet_val_paramA = true;
	}
	if(msg.port() == Prey) {
		val_Prey = x;
		isSet_val_Prey = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PlusPreyPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PlusPreyPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_paramA & isSet_val_Prey ) {
		double val = val_paramA * val_Prey;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}