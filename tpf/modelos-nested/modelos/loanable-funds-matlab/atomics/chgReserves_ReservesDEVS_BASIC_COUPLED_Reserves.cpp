#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves.h"

using namespace std;

chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves::chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves(const string &name) :
	Atomic(name),
	out_port_chgReserves_Reserves(addOutputPort("out_port_chgReserves_Reserves"))
{
}


Model &chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves::outputFunction(const CollectMessage &msg)
{
	
	return *this ;
}