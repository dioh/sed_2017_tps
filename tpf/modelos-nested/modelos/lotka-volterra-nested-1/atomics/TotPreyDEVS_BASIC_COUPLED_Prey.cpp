#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotPreyDEVS_BASIC_COUPLED_Prey.h"

using namespace std;

TotPreyDEVS_BASIC_COUPLED_Prey::TotPreyDEVS_BASIC_COUPLED_Prey(const string &name) :
	Atomic(name),
	in_plus_port_PlusPrey_Prey(addInputPort("in_plus_port_PlusPrey_Prey")),
	in_minus_port_MinusPrey_Prey(addInputPort("in_minus_port_MinusPrey_Prey")),
	isSet_PlusPrey_Prey(false),
	isSet_MinusPrey_Prey(false),
	out_port_TotPrey(addOutputPort("out_port_TotPrey"))
	{
}


Model &TotPreyDEVS_BASIC_COUPLED_Prey::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotPreyDEVS_BASIC_COUPLED_Prey::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_PlusPrey_Prey) {
		PlusPrey_Prey = x;
		isSet_PlusPrey_Prey = true;
	}
	if(msg.port() == in_minus_port_MinusPrey_Prey) {
		MinusPrey_Prey = x;
		isSet_MinusPrey_Prey = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotPreyDEVS_BASIC_COUPLED_Prey::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotPreyDEVS_BASIC_COUPLED_Prey::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_PlusPrey_Prey) { plus = plus + PlusPrey_Prey; }if(isSet_MinusPrey_Prey) { minus = minus + MinusPrey_Prey; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotPrey, out_value);
	return *this ;
}