#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgPopulationMinus.h"

using namespace std;

chgPopulationMinus::chgPopulationMinus(const string &name) :
	Atomic(name),
	Population(addInputPort("Population")),
	Betaa(addInputPort("Betaa")),
	isSet_val_Population(false),
	isSet_val_Betaa(false),
	out(addOutputPort("out"))
{
}


Model &chgPopulationMinus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgPopulationMinus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Population) {
		val_Population = x;
		isSet_val_Population = true;
	}
	if(msg.port() == Betaa) {
		val_Betaa = x;
		isSet_val_Betaa = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgPopulationMinus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgPopulationMinus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Population & isSet_val_Betaa ) {
		double val = (val_Population*val_Betaa);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}