#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "DepInvTot.h"

using namespace std;

DepInvTot::DepInvTot(const string &name) :
	Atomic(name),
	chgDepInvPlus(addInputPort("chgDepInvPlus")),
	isSet_val_chgDepInvPlus(false),
	out(addOutputPort("out"))
{
}


Model &DepInvTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &DepInvTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgDepInvPlus) {
		val_chgDepInvPlus = x;
		isSet_val_chgDepInvPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &DepInvTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &DepInvTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgDepInvPlus) {
		plus = plus + val_chgDepInvPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}