#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotDepCons.h"

using namespace std;

TotDepCons::TotDepCons(const string &name) :
	Atomic(name),
	in_plus_port_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons(addInputPort("in_plus_port_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons")),
	isSet_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons(false),
	out_port_TotDepCons(addOutputPort("out_port_TotDepCons"))
	{
}


Model &TotDepCons::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotDepCons::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons) {
		chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons = x;
		isSet_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotDepCons::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotDepCons::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons) {
		plus = plus + chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotDepCons, out_value);
		}

	return *this ;
}