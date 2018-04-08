#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgWorkersPlus.h"

using namespace std;

chgWorkersPlus::chgWorkersPlus(const string &name) :
	Atomic(name),
	Wages(addInputPort("Wages")),
	ConsW(addInputPort("ConsW")),
	isSet_val_Wages(false),
	isSet_val_ConsW(false),
	out(addOutputPort("out"))
{
}


Model &chgWorkersPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgWorkersPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Wages) {
		val_Wages = x;
		isSet_val_Wages = true;
	}
	if(msg.port() == ConsW) {
		val_ConsW = x;
		isSet_val_ConsW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgWorkersPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgWorkersPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Wages & isSet_val_ConsW ) {
		double val = (val_Wages-val_ConsW);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}