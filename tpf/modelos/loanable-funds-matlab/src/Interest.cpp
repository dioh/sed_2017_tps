#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Interest.h"

using namespace std;

Interest::Interest(const string &name) :
	Atomic(name),
	rLValue(addInputPort("rLValue")),
	Loans(addInputPort("Loans")),
	isSet_val_rLValue(false),
	isSet_val_Loans(false),
	out(addOutputPort("out"))
{
}


Model &Interest::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Interest::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == rLValue) {
		val_rLValue = x;
		isSet_val_rLValue = true;
	}
	if(msg.port() == Loans) {
		val_Loans = x;
		isSet_val_Loans = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Interest::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Interest::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_rLValue & isSet_val_Loans ) {
		double val = (val_rLValue*val_Loans);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}