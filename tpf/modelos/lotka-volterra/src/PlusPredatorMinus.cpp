#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PlusPredatorMinus.h"

using namespace std;

PlusPredatorMinus::PlusPredatorMinus(const string &name) :
	Atomic(name),
	paramD(addInputPort("paramD")),
	Prey(addInputPort("Prey")),
	Predator(addInputPort("Predator")),
	isSet_val_paramD(false),
	isSet_val_Prey(false),
	isSet_val_Predator(false),
	out(addOutputPort("out"))
{
}


Model &PlusPredatorMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PlusPredatorMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == paramD) {
		val_paramD = x;
		isSet_val_paramD = true;
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


Model &PlusPredatorMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PlusPredatorMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_paramD & isSet_val_Prey & isSet_val_Predator ) {
		double val = val_paramD * val_Prey * val_Predator;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}