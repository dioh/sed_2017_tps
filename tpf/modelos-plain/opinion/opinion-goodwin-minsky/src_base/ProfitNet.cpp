#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ProfitNet.h"

using namespace std;

ProfitNet::ProfitNet(const string &name) :
	Atomic(name),
	ProfitGrossReal(addInputPort("ProfitGrossReal")),
	InterestPayments(addInputPort("InterestPayments")),
	isSet_val_ProfitGrossReal(false),
	isSet_val_InterestPayments(false),
	out(addOutputPort("out"))
{
}


Model &ProfitNet::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ProfitNet::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == ProfitGrossReal) {
		val_ProfitGrossReal = x;
		isSet_val_ProfitGrossReal = true;
	}
	if(msg.port() == InterestPayments) {
		val_InterestPayments = x;
		isSet_val_InterestPayments = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ProfitNet::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ProfitNet::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_ProfitGrossReal & isSet_val_InterestPayments ) {
		double val = val_ProfitGrossReal - val_InterestPayments;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}