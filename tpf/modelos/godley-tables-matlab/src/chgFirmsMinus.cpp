#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgFirmsMinus.h"

using namespace std;

chgFirmsMinus::chgFirmsMinus(const string &name) :
	Atomic(name),
	LendF(addInputPort("LendF")),
	ConsW(addInputPort("ConsW")),
	ConsB(addInputPort("ConsB")),
	Interest(addInputPort("Interest")),
	Wages(addInputPort("Wages")),
	RepayF(addInputPort("RepayF")),
	isSet_val_LendF(false),
	isSet_val_ConsW(false),
	isSet_val_ConsB(false),
	isSet_val_Interest(false),
	isSet_val_Wages(false),
	isSet_val_RepayF(false),
	out(addOutputPort("out"))
{
}


Model &chgFirmsMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgFirmsMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == LendF) {
		val_LendF = x;
		isSet_val_LendF = true;
	}
	if(msg.port() == ConsW) {
		val_ConsW = x;
		isSet_val_ConsW = true;
	}
	if(msg.port() == ConsB) {
		val_ConsB = x;
		isSet_val_ConsB = true;
	}
	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	if(msg.port() == Wages) {
		val_Wages = x;
		isSet_val_Wages = true;
	}
	if(msg.port() == RepayF) {
		val_RepayF = x;
		isSet_val_RepayF = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgFirmsMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgFirmsMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_LendF & isSet_val_ConsW & isSet_val_ConsB & isSet_val_Interest & isSet_val_Wages & isSet_val_RepayF ) {
		double val = (((val_LendF+val_ConsW)+val_ConsB)-((val_Interest+val_Wages)+val_RepayF));
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}