#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "InvNWTot.h"

using namespace std;

InvNWTot::InvNWTot(const string &name) :
	Atomic(name),
	chgInvNWPlus(addInputPort("chgInvNWPlus")),
	isSet_val_chgInvNWPlus(false),
	out(addOutputPort("out"))
{
}


Model &InvNWTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &InvNWTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgInvNWPlus) {
		val_chgInvNWPlus = x;
		isSet_val_chgInvNWPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &InvNWTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &InvNWTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgInvNWPlus) {
		plus = plus + val_chgInvNWPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}