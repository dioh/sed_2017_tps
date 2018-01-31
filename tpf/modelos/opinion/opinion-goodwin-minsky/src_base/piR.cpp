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
	ProfitNet(addInputPort("ProfitNet")),
	Capital(addInputPort("Capital")),
	isSet_val_ProfitNet(false),
	isSet_val_Capital(false),
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

	if(msg.port() == ProfitNet) {
		val_ProfitNet = x;
		isSet_val_ProfitNet = true;
	}
	if(msg.port() == Capital) {
		val_Capital = x;
		isSet_val_Capital = true;
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
	if( isSet_val_ProfitNet & isSet_val_Capital ) {
		double val = val_ProfitNet / val_Capital;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}