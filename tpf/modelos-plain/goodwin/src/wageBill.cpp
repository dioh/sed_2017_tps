#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "wageBill.h"

using namespace std;

wageBill::wageBill(const string &name) :
	Atomic(name),
	wageRate(addInputPort("wageRate")),
	Labor(addInputPort("Labor")),
	isSet_val_wageRate(false),
	isSet_val_Labor(false),
	out(addOutputPort("out"))
{
}


Model &wageBill::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &wageBill::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == wageRate) {
		val_wageRate = x;
		isSet_val_wageRate = true;
	}
	if(msg.port() == Labor) {
		val_Labor = x;
		isSet_val_Labor = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &wageBill::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &wageBill::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_wageRate & isSet_val_Labor ) {
		double val = val_wageRate * val_Labor;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}