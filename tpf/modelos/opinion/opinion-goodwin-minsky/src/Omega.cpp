#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Omega.h"

using namespace std;

Omega::Omega(const string &name) :
	Atomic(name),
	Wages(addInputPort("Wages")),
	Output(addInputPort("Output")),
	isSet_val_Wages(false),
	isSet_val_Output(false),
	out(addOutputPort("out"))
{
}


Model &Omega::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Omega::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Wages) {
		val_Wages = x;
		isSet_val_Wages = true;
	}
	if(msg.port() == Output) {
		val_Output = x;
		isSet_val_Output = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Omega::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Omega::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Wages & isSet_val_Output ) {
		double val = val_Wages / val_Output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}