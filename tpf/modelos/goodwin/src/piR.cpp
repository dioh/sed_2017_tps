#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "piR.h"

using namespace std;

piR::piR(const string &name) :
	Atomic(name),
	in_ProfitNet(addInputPort("in_ProfitNet")),
	in_Capital(addInputPort("in_Capital")),
	isSet_ProfitNet(false),
	isSet_Capital(false),
	out(addOutputPort("out"))
{
}


Model &piR::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &piR::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_ProfitNet) {
		ProfitNet = x;
		isSet_ProfitNet = true;
	}
	if(msg.port() == in_Capital) {
		Capital = x;
		isSet_Capital = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &piR::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &piR::outputFunction(const CollectMessage &msg)
{
	if( isSet_ProfitNet & isSet_Capital ) {
		double val = ProfitNet / Capital;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}