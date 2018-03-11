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
	WagesC(addInputPort("WagesC")),
	WagesI(addInputPort("WagesI")),
	ConsW(addInputPort("ConsW")),
	isSet_val_WagesC(false),
	isSet_val_WagesI(false),
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

	if(msg.port() == WagesC) {
		val_WagesC = x;
		isSet_val_WagesC = true;
	}
	if(msg.port() == WagesI) {
		val_WagesI = x;
		isSet_val_WagesI = true;
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
	if( isSet_val_WagesC & isSet_val_WagesI & isSet_val_ConsW ) {
		double val = ((val_WagesC+val_WagesI)-val_ConsW);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}