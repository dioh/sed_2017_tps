#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "CapitalTot.h"

using namespace std;

CapitalTot::CapitalTot(const string &name) :
	Atomic(name),
	chgCapitalPlus(addInputPort("chgCapitalPlus")),
	isSet_val_chgCapitalPlus(false),
	out(addOutputPort("out"))
{
}


Model &CapitalTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &CapitalTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgCapitalPlus) {
		val_chgCapitalPlus = x;
		isSet_val_chgCapitalPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &CapitalTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &CapitalTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgCapitalPlus) {
		plus = plus + val_chgCapitalPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}