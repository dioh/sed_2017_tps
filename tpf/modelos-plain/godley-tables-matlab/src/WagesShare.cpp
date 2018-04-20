#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "WagesShare.h"

using namespace std;

WagesShare::WagesShare(const string &name) :
	Atomic(name),
	Wages(addInputPort("Wages")),
	GDProduct(addInputPort("GDProduct")),
	isSet_val_Wages(false),
	isSet_val_GDProduct(false),
	out(addOutputPort("out"))
{
}


Model &WagesShare::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &WagesShare::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Wages) {
		val_Wages = x;
		isSet_val_Wages = true;
	}
	if(msg.port() == GDProduct) {
		val_GDProduct = x;
		isSet_val_GDProduct = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &WagesShare::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &WagesShare::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Wages & isSet_val_GDProduct ) {
		double val = (val_Wages/val_GDProduct);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}