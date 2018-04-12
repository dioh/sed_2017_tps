#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotReservesDEVS_BASIC_COUPLED_Reserves.h"

using namespace std;

TotReservesDEVS_BASIC_COUPLED_Reserves::TotReservesDEVS_BASIC_COUPLED_Reserves(const string &name) :
	Atomic(name),
	in_plus_port_chgReserves_Reserves(addInputPort("in_plus_port_chgReserves_Reserves")),
	isSet_chgReserves_Reserves(false),
	out_port_TotReserves(addOutputPort("out_port_TotReserves"))
	{
}


Model &TotReservesDEVS_BASIC_COUPLED_Reserves::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotReservesDEVS_BASIC_COUPLED_Reserves::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgReserves_Reserves) {
		chgReserves_Reserves = x;
		isSet_chgReserves_Reserves = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotReservesDEVS_BASIC_COUPLED_Reserves::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotReservesDEVS_BASIC_COUPLED_Reserves::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgReserves_Reserves) {
		plus = plus + chgReserves_Reserves;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotReserves, out_value);
		}

	return *this ;
}