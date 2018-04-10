#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotWorkersDEVS_BASIC_COUPLED_Workers.h"

using namespace std;

TotWorkersDEVS_BASIC_COUPLED_Workers::TotWorkersDEVS_BASIC_COUPLED_Workers(const string &name) :
	Atomic(name),
	in_plus_port_chgWorkers_Workers(addInputPort("in_plus_port_chgWorkers_Workers")),
	isSet_chgWorkers_Workers(false),
	out_port_TotWorkers(addOutputPort("out_port_TotWorkers"))
	{
}


Model &TotWorkersDEVS_BASIC_COUPLED_Workers::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotWorkersDEVS_BASIC_COUPLED_Workers::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_plus_port_chgWorkers_Workers) {
		chgWorkers_Workers = x;
		isSet_chgWorkers_Workers = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotWorkersDEVS_BASIC_COUPLED_Workers::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotWorkersDEVS_BASIC_COUPLED_Workers::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_chgWorkers_Workers) {
		plus = plus + chgWorkers_Workers;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotWorkers, out_value);
		}

	return *this ;
}