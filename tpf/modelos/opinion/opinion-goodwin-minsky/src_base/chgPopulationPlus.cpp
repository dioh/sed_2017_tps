#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgPopulationPlus.h"

using namespace std;

chgPopulationPlus::chgPopulationPlus(const string &name) :
	Atomic(name),
	Betaa(addInputPort("Betaa")),
	Population(addInputPort("Population")),
	isSet_val_Betaa(false),
	isSet_val_Population(false),
	out(addOutputPort("out"))
{
}


Model &chgPopulationPlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgPopulationPlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Betaa) {
		val_Betaa = x;
		isSet_val_Betaa = true;
	}
	if(msg.port() == Population) {
		val_Population = x;
		isSet_val_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgPopulationPlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgPopulationPlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Betaa & isSet_val_Population ) {
		double val = val_Betaa * val_Population;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}