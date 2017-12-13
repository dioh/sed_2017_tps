#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Auxprofit.h"

using namespace std;

Auxprofit::Auxprofit(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_wageBill(addInputPort("in_wageBill")),
	isSet_output(false),
	isSet_wageBill(false),
	out(addOutputPort("out"))
{
}


Model &Auxprofit::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Auxprofit::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_wageBill) {
		wageBill = x;
		isSet_wageBill = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Auxprofit::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Auxprofit::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_wageBill ) {
		double val = output - wageBill;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}