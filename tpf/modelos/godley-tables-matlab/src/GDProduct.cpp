#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "GDProduct.h"

using namespace std;

GDProduct::GDProduct(const string &name) :
	Atomic(name),
	Firms(addInputPort("Firms")),
	tauT(addInputPort("tauT")),
	isSet_val_Firms(false),
	isSet_val_tauT(false),
	out(addOutputPort("out"))
{
}


Model &GDProduct::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &GDProduct::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Firms) {
		val_Firms = x;
		isSet_val_Firms = true;
	}
	if(msg.port() == tauT) {
		val_tauT = x;
		isSet_val_tauT = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &GDProduct::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &GDProduct::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Firms & isSet_val_tauT ) {
		double val = (val_Firms/val_tauT);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}