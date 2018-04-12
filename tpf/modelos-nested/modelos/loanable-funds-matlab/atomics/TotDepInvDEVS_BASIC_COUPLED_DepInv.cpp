#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotDepInvDEVS_BASIC_COUPLED_DepInv.h"

using namespace std;

TotDepInvDEVS_BASIC_COUPLED_DepInv::TotDepInvDEVS_BASIC_COUPLED_DepInv(const string &name) :
	Atomic(name),
	in_plus_port_chgDepInv_DepInv(addInputPort("in_plus_port_chgDepInv_DepInv")),
	isSet_chgDepInv_DepInv(false),
	out_port_TotDepInv(addOutputPort("out_port_TotDepInv"))
	{
}


Model &TotDepInvDEVS_BASIC_COUPLED_DepInv::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotDepInvDEVS_BASIC_COUPLED_DepInv::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgDepInv_DepInv) {
		chgDepInv_DepInv = x;
		isSet_chgDepInv_DepInv = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotDepInvDEVS_BASIC_COUPLED_DepInv::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotDepInvDEVS_BASIC_COUPLED_DepInv::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgDepInv_DepInv) {
		plus = plus + chgDepInv_DepInv;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotDepInv, out_value);
		}

	return *this ;
}