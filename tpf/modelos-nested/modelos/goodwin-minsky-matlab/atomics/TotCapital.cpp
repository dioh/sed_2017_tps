#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotCapital.h"

using namespace std;

TotCapital::TotCapital(const string &name) :
	Atomic(name),
	in_plus_port_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital(addInputPort("in_plus_port_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital")),
	isSet_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital(false),
	out_port_TotCapital(addOutputPort("out_port_TotCapital"))
	{
}


Model &TotCapital::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotCapital::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital) {
		chgCapital_CapitalDEVS_BASIC_COUPLED_Capital = x;
		isSet_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotCapital::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotCapital::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital) {
		plus = plus + chgCapital_CapitalDEVS_BASIC_COUPLED_Capital;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotCapital, out_value);
		}

	return *this ;
}