#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotWorkers.h"

using namespace std;

TotWorkers::TotWorkers(const string &name) :
	Atomic(name),
	in_plus_port_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers(addInputPort("in_plus_port_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers")),
	isSet_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers(false),
	out_port_TotWorkers(addOutputPort("out_port_TotWorkers"))
	{
}


Model &TotWorkers::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotWorkers::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers) {
		chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers = x;
		isSet_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotWorkers::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotWorkers::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers) {
		plus = plus + chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotWorkers, out_value);
		}

	return *this ;
}