#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_Recovered_Recovering.h"

using namespace std;

fp_Recovered_Recovering::fp_Recovered_Recovering(const string &name) :
	Atomic(name),
	in_Infectious(addInputPort("in_Infectious")),
	in_Duration(addInputPort("in_Duration")),
	isSet_Infectious(false),
	isSet_Duration(false),
	out(addOutputPort("out"))

{
}


Model &fp_Recovered_Recovering::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_Recovered_Recovering::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Infectious) {
		Infectious = x;
		isSet_Infectious = true;
	}
	if(msg.port() == in_Duration) {
		Duration = x;
		isSet_Duration = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_Recovered_Recovering::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_Recovered_Recovering::outputFunction(const CollectMessage &msg)
{
	if( isSet_Infectious & isSet_Duration ) {
		double val = Infectious/Duration;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}