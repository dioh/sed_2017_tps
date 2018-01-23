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
	Capital(addInputPort("Capital")),
	velocityOfMoney(addInputPort("velocityOfMoney")),
	isSet_val_Capital(false),
	isSet_val_velocityOfMoney(false),
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

	if(msg.port() == Capital) {
		val_Capital = x;
		isSet_val_Capital = true;
	}
	if(msg.port() == velocityOfMoney) {
		val_velocityOfMoney = x;
		isSet_val_velocityOfMoney = true;
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
	if( isSet_val_Capital & isSet_val_velocityOfMoney ) {
		double val = (val_Capital/val_velocityOfMoney);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}