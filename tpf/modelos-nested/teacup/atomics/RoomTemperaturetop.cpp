#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "RoomTemperaturetop.h"

using namespace std;

RoomTemperaturetop::RoomTemperaturetop(const string &name) :
    RoomTemperature(addInputPort("RoomTemperature")),
    RoomTemperaturetop(addOutputPort("RoomTemperaturetop")),
    RoomTemperature(-1),
    Atomic(name)
{
}


Model &RoomTemperaturetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &RoomTemperaturetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == RoomTemperature) {
    	RoomTemperature = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &RoomTemperaturetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &RoomTemperaturetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { RoomTemperature };
	sendOutput(msg.time(),  RoomTemperaturetop, out_value);
    return *this ;
}