#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ProfitShare.h"

using namespace std;

ProfitShare::ProfitShare(const string &name) :
	Atomic(name),
	ProfitNet(addInputPort("ProfitNet")),
	GDProduct(addInputPort("GDProduct")),
	isSet_val_ProfitNet(false),
	isSet_val_GDProduct(false),
	out(addOutputPort("out"))
{
}


Model &ProfitShare::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ProfitShare::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == ProfitNet) {
		val_ProfitNet = x;
		isSet_val_ProfitNet = true;
	}
	if(msg.port() == GDProduct) {
		val_GDProduct = x;
		isSet_val_GDProduct = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ProfitShare::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ProfitShare::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_ProfitNet & isSet_val_GDProduct ) {
		double val = (val_ProfitNet/val_GDProduct);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}