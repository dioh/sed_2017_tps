#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_LaborProductivity_chgLaborProductivity.h"

using namespace std;

fp_LaborProductivity_chgLaborProductivity::fp_LaborProductivity_chgLaborProductivity(const string &name) :
	Atomic(name),
	in_Alphaa(addInputPort("in_Alphaa")),
	in_LaborProductivity(addInputPort("in_LaborProductivity")),
	isSet_Alphaa(false),
	isSet_LaborProductivity(false),
	out(addOutputPort("out"))

{
}


Model &fp_LaborProductivity_chgLaborProductivity::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_LaborProductivity_chgLaborProductivity::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Alphaa) {
		Alphaa = x;
		isSet_Alphaa = true;
	}
	if(msg.port() == in_LaborProductivity) {
		LaborProductivity = x;
		isSet_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_LaborProductivity_chgLaborProductivity::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_LaborProductivity_chgLaborProductivity::outputFunction(const CollectMessage &msg)
{
	if( isSet_Alphaa & isSet_LaborProductivity ) {
		double val = Alphaa * LaborProductivity;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}