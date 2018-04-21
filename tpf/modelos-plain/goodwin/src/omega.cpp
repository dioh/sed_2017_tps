#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "omega.h"

using namespace std;

omega::omega(const string &name) :
	Atomic(name),
	wageBill(addInputPort("wageBill")),
	Output(addInputPort("Output")),
	isSet_val_wageBill(false),
	isSet_val_Output(false),
	out(addOutputPort("out"))
{
}


Model &omega::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &omega::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == wageBill) {
		val_wageBill = x;
		isSet_val_wageBill = true;
	}
	if(msg.port() == Output) {
		val_Output = x;
		isSet_val_Output = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &omega::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &omega::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_wageBill & isSet_val_Output ) {
		double val = val_wageBill / val_Output;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}