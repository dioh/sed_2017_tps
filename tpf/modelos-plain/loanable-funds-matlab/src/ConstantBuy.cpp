#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ConstantBuy.h"

using namespace std;

ConstantBuy::ConstantBuy(const string &name) :
	Atomic(name),
	PiCG(addInputPort("PiCG")),
	CPIValue(addInputPort("CPIValue")),
	isSet_val_PiCG(false),
	isSet_val_CPIValue(false),
	out(addOutputPort("out"))
{
}


Model &ConstantBuy::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ConstantBuy::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == PiCG) {
		val_PiCG = x;
		isSet_val_PiCG = true;
	}
	if(msg.port() == CPIValue) {
		val_CPIValue = x;
		isSet_val_CPIValue = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ConstantBuy::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ConstantBuy::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_PiCG & isSet_val_CPIValue ) {
		double val = (val_PiCG*val_CPIValue);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}