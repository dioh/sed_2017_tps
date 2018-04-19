#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotDepInv.h"

using namespace std;

TotDepInv::TotDepInv(const string &name) :
	Atomic(name),
	in_plus_port_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv(addInputPort("in_plus_port_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv")),
	isSet_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv(false),
	out_port_TotDepInv(addOutputPort("out_port_TotDepInv"))
	{
}


Model &TotDepInv::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotDepInv::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv) {
		chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv = x;
		isSet_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotDepInv::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotDepInv::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv) {
		plus = plus + chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotDepInv, out_value);
		}

	return *this ;
}