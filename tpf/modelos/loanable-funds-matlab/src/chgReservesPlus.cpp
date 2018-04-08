#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgReservesPlus.h"

using namespace std;

chgReservesPlus::chgReservesPlus(const string &name) :
	Atomic(name),
	out(addOutputPort("out"))
{
}


Model &chgReservesPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgReservesPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgReservesPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgReservesPlus::outputFunction(const CollectMessage &msg)
{
	
	double val = 0;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out, out_value);
	
	return *this ;
}