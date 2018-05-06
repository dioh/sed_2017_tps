#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotCapitalDEVS_BASIC_COUPLED_Capital.h"

using namespace std;

TotCapitalDEVS_BASIC_COUPLED_Capital::TotCapitalDEVS_BASIC_COUPLED_Capital(const string &name) :
	Atomic(name),
	in_plus_port_chgCapital_Capital(addInputPort("in_plus_port_chgCapital_Capital")),
	isSet_chgCapital_Capital(false),
	out_port_TotCapital(addOutputPort("out_port_TotCapital"))
	{
}


Model &TotCapitalDEVS_BASIC_COUPLED_Capital::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotCapitalDEVS_BASIC_COUPLED_Capital::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgCapital_Capital) {
		chgCapital_Capital = x;
		isSet_chgCapital_Capital = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotCapitalDEVS_BASIC_COUPLED_Capital::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotCapitalDEVS_BASIC_COUPLED_Capital::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_chgCapital_Capital) { plus = plus + chgCapital_Capital; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotCapital, out_value);
	return *this ;
}