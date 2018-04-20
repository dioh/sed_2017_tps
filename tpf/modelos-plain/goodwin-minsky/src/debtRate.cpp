#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "debtRate.h"

using namespace std;

debtRate::debtRate(const string &name) :
	Atomic(name),
	Debt(addInputPort("Debt")),
	Output(addInputPort("Output")),
	isSet_val_Debt(false),
	isSet_val_Output(false),
	out(addOutputPort("out"))
{
}


Model &debtRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &debtRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Debt) {
		val_Debt = x;
		isSet_val_Debt = true;
	}
	if(msg.port() == Output) {
		val_Output = x;
		isSet_val_Output = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &debtRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &debtRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Debt & isSet_val_Output ) {
		double val = val_Debt / val_Output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}