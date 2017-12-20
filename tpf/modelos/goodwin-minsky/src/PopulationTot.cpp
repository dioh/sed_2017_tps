#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "PopulationTot.h"

using namespace std;

PopulationTot::PopulationTot(const string &name) :
	Atomic(name),
	chgPopulationPlus(addInputPort("chgPopulationPlus")),
	isSet_val_chgPopulationPlus(false),
	out(addOutputPort("out"))
{
}


Model &PopulationTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &PopulationTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgPopulationPlus) {
		val_chgPopulationPlus = x;
		isSet_val_chgPopulationPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &PopulationTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &PopulationTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_chgPopulationPlus ) {
		plus = plus + val_chgPopulationPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}