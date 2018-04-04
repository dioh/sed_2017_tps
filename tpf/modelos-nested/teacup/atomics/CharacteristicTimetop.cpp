#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "CharacteristicTimetop.h"

using namespace std;

CharacteristicTimetop::CharacteristicTimetop(const string &name) :
    CharacteristicTime(addInputPort("CharacteristicTime")),
    CharacteristicTimetop(addOutputPort("CharacteristicTimetop")),
    CharacteristicTime(-1),
    Atomic(name)
{
}


Model &CharacteristicTimetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &CharacteristicTimetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == CharacteristicTime) {
    	CharacteristicTime = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &CharacteristicTimetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &CharacteristicTimetop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { CharacteristicTime };
	sendOutput(msg.time(),  CharacteristicTimetop, out_value);
    return *this ;
}