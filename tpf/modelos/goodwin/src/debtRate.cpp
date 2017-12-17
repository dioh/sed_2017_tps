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
	in_Debt(addInputPort("in_Debt")),
	in_Output(addInputPort("in_Output")),
	isSet_Debt(false),
	isSet_Output(false),
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

	if(msg.port() == in_Debt) {
		Debt = x;
		isSet_Debt = true;
	}
	if(msg.port() == in_Output) {
		Output = x;
		isSet_Output = true;
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
	if( isSet_Debt & isSet_Output ) {
		double val = Debt / Output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}