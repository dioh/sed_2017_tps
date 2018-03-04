#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxprofitGrossReal.h"

using namespace std;

AuxprofitGrossReal::AuxprofitGrossReal(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_wages(addInputPort("in_wages")),
	isSet_output(false),
	isSet_wages(false),
	out(addOutputPort("out"))
{
}


Model &AuxprofitGrossReal::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxprofitGrossReal::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_wages) {
		wages = x;
		isSet_wages = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxprofitGrossReal::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxprofitGrossReal::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_wages ) {
		double val = output - wages;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}