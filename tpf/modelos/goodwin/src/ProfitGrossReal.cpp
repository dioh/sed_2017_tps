#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ProfitGrossReal.h"

using namespace std;

ProfitGrossReal::ProfitGrossReal(const string &name) :
	Atomic(name),
	in_Output(addInputPort("in_Output")),
	in_Wages(addInputPort("in_Wages")),
	isSet_Output(false),
	isSet_Wages(false),
	out(addOutputPort("out"))
{
}


Model &ProfitGrossReal::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ProfitGrossReal::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Output) {
		Output = x;
		isSet_Output = true;
	}
	if(msg.port() == in_Wages) {
		Wages = x;
		isSet_Wages = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ProfitGrossReal::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ProfitGrossReal::outputFunction(const CollectMessage &msg)
{
	if( isSet_Output & isSet_Wages ) {
		double val = Output - Wages;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}