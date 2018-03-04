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
	Output(addInputPort("Output")),
	Wages(addInputPort("Wages")),
	isSet_val_Output(false),
	isSet_val_Wages(false),
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

	if(msg.port() == Output) {
		val_Output = x;
		isSet_val_Output = true;
	}
	if(msg.port() == Wages) {
		val_Wages = x;
		isSet_val_Wages = true;
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
	if( isSet_val_Output & isSet_val_Wages ) {
		double val = val_Output - val_Wages;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}