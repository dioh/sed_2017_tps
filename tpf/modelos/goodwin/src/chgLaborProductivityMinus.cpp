#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgLaborProductivityMinus.h"

using namespace std;

chgLaborProductivityMinus::chgLaborProductivityMinus(const string &name) :
	Atomic(name),
	LaborProductivity(addInputPort("LaborProductivity")),
	isSet_val_LaborProductivity(false),
	out(addOutputPort("out"))
{
}


Model &chgLaborProductivityMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgLaborProductivityMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == LaborProductivity) {
		val_LaborProductivity = x;
		isSet_val_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgLaborProductivityMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgLaborProductivityMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_LaborProductivity ) {
		double val = val_LaborProductivity * 0.025;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}