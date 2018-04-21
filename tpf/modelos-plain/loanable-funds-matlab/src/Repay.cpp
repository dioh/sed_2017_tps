#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Repay.h"

using namespace std;

Repay::Repay(const string &name) :
	Atomic(name),
	Loans(addInputPort("Loans")),
	tauR(addInputPort("tauR")),
	isSet_val_Loans(false),
	isSet_val_tauR(false),
	out(addOutputPort("out"))
{
}


Model &Repay::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Repay::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Loans) {
		val_Loans = x;
		isSet_val_Loans = true;
	}
	if(msg.port() == tauR) {
		val_tauR = x;
		isSet_val_tauR = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Repay::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Repay::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Loans & isSet_val_tauR ) {
		double val = (val_Loans/val_tauR);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}