#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "populationDeath_hunterDEVS_BASIC_COUPLED_hunter.h"

using namespace std;

populationDeath_hunterDEVS_BASIC_COUPLED_hunter::populationDeath_hunterDEVS_BASIC_COUPLED_hunter(const string &name) :
	Atomic(name),
    hunter(addInputPort("hunter")),
    isSet_hunter(false),
	populationDeath_hunterDEVS_BASIC_COUPLED_hunter(addOutputPort("populationDeath_hunterDEVS_BASIC_COUPLED_hunter"))
{
}


Model &populationDeath_hunterDEVS_BASIC_COUPLED_hunter::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &populationDeath_hunterDEVS_BASIC_COUPLED_hunter::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == hunter) {
		hunter = x;
		isSet_hunter = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &populationDeath_hunterDEVS_BASIC_COUPLED_hunter::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &populationDeath_hunterDEVS_BASIC_COUPLED_hunter::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_hunter ) {
	    Tuple<Real> out_value { 0.05 * hunter };
		sendOutput(msg.time(), populationDeath_hunterDEVS_BASIC_COUPLED_hunter, out_value);
	}
	
	return *this ;
}