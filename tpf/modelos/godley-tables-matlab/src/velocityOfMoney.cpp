#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "velocityOfMoney.h"

using namespace std;

velocityOfMoney::velocityOfMoney(const string &name) :
	Atomic(name),
	GDProduct(addInputPort("GDProduct")),
	Money(addInputPort("Money")),
	isSet_val_GDProduct(false),
	isSet_val_Money(false),
	out(addOutputPort("out"))
{
}


Model &velocityOfMoney::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &velocityOfMoney::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == GDProduct) {
		val_GDProduct = x;
		isSet_val_GDProduct = true;
	}
	if(msg.port() == Money) {
		val_Money = x;
		isSet_val_Money = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &velocityOfMoney::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &velocityOfMoney::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_GDProduct & isSet_val_Money ) {
		double val = (val_GDProduct/val_Money);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}