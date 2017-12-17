#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "fp_Population_chgPopulation.h"

using namespace std;

fp_Population_chgPopulation::fp_Population_chgPopulation(const string &name) :
	Atomic(name),
	in_Betaa(addInputPort("in_Betaa")),
	in_Population(addInputPort("in_Population")),
	isSet_Betaa(false),
	isSet_Population(false),
	out(addOutputPort("out"))

{
}


Model &fp_Population_chgPopulation::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &fp_Population_chgPopulation::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Betaa) {
		Betaa = x;
		isSet_Betaa = true;
	}
	if(msg.port() == in_Population) {
		Population = x;
		isSet_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &fp_Population_chgPopulation::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &fp_Population_chgPopulation::outputFunction(const CollectMessage &msg)
{
	if( isSet_Betaa & isSet_Population ) {
		double val = Betaa * Population;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}