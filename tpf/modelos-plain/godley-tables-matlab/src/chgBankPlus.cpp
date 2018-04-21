#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgBankPlus.h"

using namespace std;

chgBankPlus::chgBankPlus(const string &name) :
	Atomic(name),
	Interest(addInputPort("Interest")),
	ConsB(addInputPort("ConsB")),
	isSet_val_Interest(false),
	isSet_val_ConsB(false),
	out(addOutputPort("out"))
{
}


Model &chgBankPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgBankPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	if(msg.port() == ConsB) {
		val_ConsB = x;
		isSet_val_ConsB = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgBankPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgBankPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Interest & isSet_val_ConsB ) {
		double val = (val_Interest-val_ConsB);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}