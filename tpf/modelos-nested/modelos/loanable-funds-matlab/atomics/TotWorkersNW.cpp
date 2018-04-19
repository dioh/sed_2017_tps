#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotWorkersNW.h"

using namespace std;

TotWorkersNW::TotWorkersNW(const string &name) :
	Atomic(name),
	in_plus_port_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW(addInputPort("in_plus_port_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW")),
	isSet_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW(false),
	out_port_TotWorkersNW(addOutputPort("out_port_TotWorkersNW"))
	{
}


Model &TotWorkersNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotWorkersNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW) {
		chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW = x;
		isSet_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotWorkersNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotWorkersNW::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW) {
		plus = plus + chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotWorkersNW, out_value);
		}

	return *this ;
}