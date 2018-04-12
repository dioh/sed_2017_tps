#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotConsNWDEVS_BASIC_COUPLED_ConsNW.h"

using namespace std;

TotConsNWDEVS_BASIC_COUPLED_ConsNW::TotConsNWDEVS_BASIC_COUPLED_ConsNW(const string &name) :
	Atomic(name),
	in_plus_port_chgConsNW_ConsNW(addInputPort("in_plus_port_chgConsNW_ConsNW")),
	isSet_chgConsNW_ConsNW(false),
	out_port_TotConsNW(addOutputPort("out_port_TotConsNW"))
	{
}


Model &TotConsNWDEVS_BASIC_COUPLED_ConsNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotConsNWDEVS_BASIC_COUPLED_ConsNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgConsNW_ConsNW) {
		chgConsNW_ConsNW = x;
		isSet_chgConsNW_ConsNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotConsNWDEVS_BASIC_COUPLED_ConsNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotConsNWDEVS_BASIC_COUPLED_ConsNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgConsNW_ConsNW) {
		plus = plus + chgConsNW_ConsNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotConsNW, out_value);
		}

	return *this ;
}