#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgLoansMinus.h"

using namespace std;

chgLoansMinus::chgLoansMinus(const string &name) :
	Atomic(name),
	Lend(addInputPort("Lend")),
	Repay(addInputPort("Repay")),
	isSet_val_Lend(false),
	isSet_val_Repay(false),
	out(addOutputPort("out"))
{
}


Model &chgLoansMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgLoansMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Lend) {
		val_Lend = x;
		isSet_val_Lend = true;
	}
	if(msg.port() == Repay) {
		val_Repay = x;
		isSet_val_Repay = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgLoansMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgLoansMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Lend & isSet_val_Repay ) {
		double val = (val_Lend-val_Repay);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}