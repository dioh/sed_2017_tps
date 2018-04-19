#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotConsNW.h"

using namespace std;

TotConsNW::TotConsNW(const string &name) :
	Atomic(name),
	in_plus_port_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW(addInputPort("in_plus_port_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW")),
	isSet_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW(false),
	out_port_TotConsNW(addOutputPort("out_port_TotConsNW"))
	{
}


Model &TotConsNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotConsNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW) {
		chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW = x;
		isSet_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotConsNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotConsNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW) {
		plus = plus + chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotConsNW, out_value);
		}

	return *this ;
}