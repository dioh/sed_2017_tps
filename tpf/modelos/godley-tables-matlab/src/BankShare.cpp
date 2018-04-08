#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "BankShare.h"

using namespace std;

BankShare::BankShare(const string &name) :
	Atomic(name),
	Interest(addInputPort("Interest")),
	GDProduct(addInputPort("GDProduct")),
	isSet_val_Interest(false),
	isSet_val_GDProduct(false),
	out(addOutputPort("out"))
{
}


Model &BankShare::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &BankShare::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Interest) {
		val_Interest = x;
		isSet_val_Interest = true;
	}
	if(msg.port() == GDProduct) {
		val_GDProduct = x;
		isSet_val_GDProduct = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &BankShare::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &BankShare::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Interest & isSet_val_GDProduct ) {
		double val = (val_Interest/val_GDProduct);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}