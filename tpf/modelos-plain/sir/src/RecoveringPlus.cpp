#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "RecoveringPlus.h"

using namespace std;

RecoveringPlus::RecoveringPlus(const string &name) :
	Atomic(name),
	Infected(addInputPort("Infected")),
	Duration(addInputPort("Duration")),
	isSet_val_Infected(false),
	isSet_val_Duration(false),
	out(addOutputPort("out"))
{
}


Model &RecoveringPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &RecoveringPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Infected) {
		val_Infected = x;
		isSet_val_Infected = true;
	}
	if(msg.port() == Duration) {
		val_Duration = x;
		isSet_val_Duration = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &RecoveringPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &RecoveringPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Infected & isSet_val_Duration ) {
		double val = val_Infected / val_Duration;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}