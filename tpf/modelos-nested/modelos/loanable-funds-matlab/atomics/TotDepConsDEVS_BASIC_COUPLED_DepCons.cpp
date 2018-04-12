#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotDepConsDEVS_BASIC_COUPLED_DepCons.h"

using namespace std;

TotDepConsDEVS_BASIC_COUPLED_DepCons::TotDepConsDEVS_BASIC_COUPLED_DepCons(const string &name) :
	Atomic(name),
	in_plus_port_chgDepCons_DepCons(addInputPort("in_plus_port_chgDepCons_DepCons")),
	isSet_chgDepCons_DepCons(false),
	out_port_TotDepCons(addOutputPort("out_port_TotDepCons"))
	{
}


Model &TotDepConsDEVS_BASIC_COUPLED_DepCons::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotDepConsDEVS_BASIC_COUPLED_DepCons::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgDepCons_DepCons) {
		chgDepCons_DepCons = x;
		isSet_chgDepCons_DepCons = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotDepConsDEVS_BASIC_COUPLED_DepCons::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotDepConsDEVS_BASIC_COUPLED_DepCons::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgDepCons_DepCons) {
		plus = plus + chgDepCons_DepCons;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotDepCons, out_value);
		}

	return *this ;
}