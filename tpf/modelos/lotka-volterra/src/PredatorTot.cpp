#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PredatorTot.h"

using namespace std;

PredatorTot::PredatorTot(const string &name) :
	Atomic(name),
	PlusPredatorPlus(addInputPort("PlusPredatorPlus")),
	isSet_val_PlusPredatorPlus(false),
	out(addOutputPort("out"))
{
}


Model &PredatorTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PredatorTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == PlusPredatorPlus) {
		val_PlusPredatorPlus = x;
		isSet_val_PlusPredatorPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PredatorTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PredatorTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_PlusPredatorPlus ) {
		plus = plus + val_PlusPredatorPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}