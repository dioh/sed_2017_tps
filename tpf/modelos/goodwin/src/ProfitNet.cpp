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
	in_ProfitGrossReal(addInputPort("in_ProfitGrossReal")),
	in_InterestPayments(addInputPort("in_InterestPayments")),
	isSet_ProfitGrossReal(false),
	isSet_InterestPayments(false),
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

	if(msg.port() == in_ProfitGrossReal) {
		ProfitGrossReal = x;
		isSet_ProfitGrossReal = true;
	}
	if(msg.port() == in_InterestPayments) {
		InterestPayments = x;
		isSet_InterestPayments = true;
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
	if( isSet_ProfitGrossReal & isSet_InterestPayments ) {
		double val = ProfitGrossReal - InterestPayments;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}