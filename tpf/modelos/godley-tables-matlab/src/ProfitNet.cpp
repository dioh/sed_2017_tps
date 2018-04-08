#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ProfitNet.h"

using namespace std;

ProfitNet::ProfitNet(const string &name) :
	Atomic(name),
	ProfitGross(addInputPort("ProfitGross")),
	Interest(addInputPort("Interest")),
	isSet_val_ProfitGross(false),
	isSet_val_Interest(false),
	out(addOutputPort("out"))
{
}


Model &ProfitNet::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ProfitNet::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == ProfitGross) {
		val_ProfitGross = x;
		isSet_val_ProfitGross = true;
	}
	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ProfitNet::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ProfitNet::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_ProfitGross & isSet_val_Interest ) {
		double val = (val_ProfitGross-val_Interest);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}