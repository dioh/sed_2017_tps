#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers.h"

using namespace std;

chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers::chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers(const string &name) :
	Atomic(name),
    in_port_ConsW(addInputPort("in_port_ConsW")),
    in_port_WagesC(addInputPort("in_port_WagesC")),
    in_port_WagesI(addInputPort("in_port_WagesI")),
    isSet_ConsW(false),
    isSet_WagesC(false),
    isSet_WagesI(false),
	out_port_chgWorkers_Workers(addOutputPort("out_port_chgWorkers_Workers"))
{
}


Model &chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_ConsW) {
		ConsW = x;
		isSet_ConsW = true;
	}
	if(msg.port() == in_port_WagesC) {
		WagesC = x;
		isSet_WagesC = true;
	}
	if(msg.port() == in_port_WagesI) {
		WagesI = x;
		isSet_WagesI = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_ConsW & isSet_WagesC & isSet_WagesI ) {
	    Tuple<Real> out_value { ((WagesC+WagesI)-ConsW) };
		sendOutput(msg.time(), out_port_chgWorkers_Workers, out_value);
	}
	
	return *this ;
}