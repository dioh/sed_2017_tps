#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxprofitNet.h"

using namespace std;

AuxprofitNet::AuxprofitNet(const string &name) :
	Atomic(name),
	in_interestPayments(addInputPort("in_interestPayments")),
	in_profitGrossReal(addInputPort("in_profitGrossReal")),
	isSet_interestPayments(false),
	isSet_profitGrossReal(false),
	out(addOutputPort("out"))
{
}


Model &AuxprofitNet::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxprofitNet::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_interestPayments) {
		interestPayments = x;
		isSet_interestPayments = true;
	}
	if(msg.port() == in_profitGrossReal) {
		profitGrossReal = x;
		isSet_profitGrossReal = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxprofitNet::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxprofitNet::outputFunction(const CollectMessage &msg)
{
	if( isSet_interestPayments & isSet_profitGrossReal ) {
		double val = profitGrossReal - interestPayments;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}