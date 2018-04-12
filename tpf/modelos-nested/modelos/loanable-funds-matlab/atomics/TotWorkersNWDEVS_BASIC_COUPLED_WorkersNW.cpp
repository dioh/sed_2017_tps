#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW.h"

using namespace std;

TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW::TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW(const string &name) :
	Atomic(name),
	in_plus_port_chgWorkersNW_WorkersNW(addInputPort("in_plus_port_chgWorkersNW_WorkersNW")),
	isSet_chgWorkersNW_WorkersNW(false),
	out_port_TotWorkersNW(addOutputPort("out_port_TotWorkersNW"))
	{
}


Model &TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgWorkersNW_WorkersNW) {
		chgWorkersNW_WorkersNW = x;
		isSet_chgWorkersNW_WorkersNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgWorkersNW_WorkersNW) {
		plus = plus + chgWorkersNW_WorkersNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotWorkersNW, out_value);
		}

	return *this ;
}