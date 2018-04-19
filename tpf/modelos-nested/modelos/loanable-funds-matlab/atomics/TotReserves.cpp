#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotReserves.h"

using namespace std;

TotReserves::TotReserves(const string &name) :
	Atomic(name),
	in_plus_port_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves(addInputPort("in_plus_port_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves")),
	isSet_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves(false),
	out_port_TotReserves(addOutputPort("out_port_TotReserves"))
	{
}


Model &TotReserves::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotReserves::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves) {
		chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves = x;
		isSet_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotReserves::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotReserves::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves) {
		plus = plus + chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotReserves, out_value);
		}

	return *this ;
}