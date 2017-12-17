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
	in_Wages(addInputPort("in_Wages")),
	in_Output(addInputPort("in_Output")),
	isSet_Wages(false),
	isSet_Output(false),
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

	if(msg.port() == in_Wages) {
		Wages = x;
		isSet_Wages = true;
	}
	if(msg.port() == in_Output) {
		Output = x;
		isSet_Output = true;
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
	if( isSet_Wages & isSet_Output ) {
		double val = Wages / Output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}