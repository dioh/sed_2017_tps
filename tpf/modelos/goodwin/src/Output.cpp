#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Output.h"

using namespace std;

Output::Output(const string &name) :
	Atomic(name),
	in_Capital(addInputPort("in_Capital")),
	in_velocityOfMoney(addInputPort("in_velocityOfMoney")),
	isSet_Capital(false),
	isSet_velocityOfMoney(false),
	out(addOutputPort("out"))
{
}


Model &Output::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Output::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Capital) {
		Capital = x;
		isSet_Capital = true;
	}
	if(msg.port() == in_velocityOfMoney) {
		velocityOfMoney = x;
		isSet_velocityOfMoney = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Output::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Output::outputFunction(const CollectMessage &msg)
{
	if( isSet_Capital & isSet_velocityOfMoney ) {
		double val = Capital / velocityOfMoney;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}