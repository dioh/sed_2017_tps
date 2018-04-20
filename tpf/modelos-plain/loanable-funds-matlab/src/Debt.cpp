#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Debt.h"

using namespace std;

Debt::Debt(const string &name) :
	Atomic(name),
	Loans(addInputPort("Loans")),
	isSet_val_Loans(false),
	out(addOutputPort("out"))
{
}


Model &Debt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Debt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Loans) {
		val_Loans = x;
		isSet_val_Loans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Debt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Debt::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Loans ) {
		double val = val_Loans;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}