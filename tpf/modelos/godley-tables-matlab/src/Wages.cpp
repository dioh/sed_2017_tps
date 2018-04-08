#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Wages.h"

using namespace std;

Wages::Wages(const string &name) :
	Atomic(name),
	GDProduct(addInputPort("GDProduct")),
	share(addInputPort("share")),
	isSet_val_GDProduct(false),
	isSet_val_share(false),
	out(addOutputPort("out"))
{
}


Model &Wages::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Wages::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == GDProduct) {
		val_GDProduct = x;
		isSet_val_GDProduct = true;
	}
	if(msg.port() == share) {
		val_share = x;
		isSet_val_share = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Wages::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Wages::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_GDProduct & isSet_val_share ) {
		double val = (val_GDProduct*(1.0-val_share));
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}