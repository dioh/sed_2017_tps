#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ProfitGross.h"

using namespace std;

ProfitGross::ProfitGross(const string &name) :
	Atomic(name),
	GDProduct(addInputPort("GDProduct")),
	Wages(addInputPort("Wages")),
	isSet_val_GDProduct(false),
	isSet_val_Wages(false),
	out(addOutputPort("out"))
{
}


Model &ProfitGross::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ProfitGross::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == GDProduct) {
		val_GDProduct = x;
		isSet_val_GDProduct = true;
	}
	if(msg.port() == Wages) {
		val_Wages = x;
		isSet_val_Wages = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ProfitGross::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ProfitGross::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_GDProduct & isSet_val_Wages ) {
		double val = (val_GDProduct-val_Wages);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}