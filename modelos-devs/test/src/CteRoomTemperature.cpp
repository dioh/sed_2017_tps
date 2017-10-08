#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "CteRoomTemperature.h"

using namespace std;

CteRoomTemperature::CteRoomTemperature(const string &name) :
	Atomic(name),
	inVal(addInputPort("inVal")),
	out(addOutputPort("out")),
	val(-1)
{
}


Model &CteRoomTemperature::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &CteRoomTemperature::externalFunction(const ExternalMessage &msg)
{
	
	cout << "external function CTERT" << endl;
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	cout << "VALOR : " << x << endl;

	if(msg.port() == inVal) {
		val = x;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &CteRoomTemperature::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &CteRoomTemperature::outputFunction(const CollectMessage &msg)
{
	cout << "CteRoomTemperature manda output por out" << endl;
	Tuple<Real> out_value { val };

	sendOutput(msg.time(), out, out_value);
	return *this ;
}
