#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgReservesMinus.h"

using namespace std;

chgReservesMinus::chgReservesMinus(const string &name) :
	Atomic(name),
	out(addOutputPort("out"))
{
}


Model &chgReservesMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgReservesMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgReservesMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgReservesMinus::outputFunction(const CollectMessage &msg)
{
	
	double val = 0;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out, out_value);
	
	return *this ;
}