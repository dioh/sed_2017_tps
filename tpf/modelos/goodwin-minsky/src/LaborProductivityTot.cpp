#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "LaborProductivityTot.h"

using namespace std;

LaborProductivityTot::LaborProductivityTot(const string &name) :
	Atomic(name),
	chgLaborProductivityPlus(addInputPort("chgLaborProductivityPlus")),
	isSet_val_chgLaborProductivityPlus(false),
	out(addOutputPort("out"))
{
}


Model &LaborProductivityTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &LaborProductivityTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgLaborProductivityPlus) {
		val_chgLaborProductivityPlus = x;
		isSet_val_chgLaborProductivityPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &LaborProductivityTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &LaborProductivityTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_chgLaborProductivityPlus ) {
		plus = plus + val_chgLaborProductivityPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}