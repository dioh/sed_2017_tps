#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW.h"

using namespace std;

chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW::chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW(const string &name) :
	Atomic(name),
    in_port_WagesC(addInputPort("in_port_WagesC")),
    in_port_WagesI(addInputPort("in_port_WagesI")),
    in_port_ConsW(addInputPort("in_port_ConsW")),
    isSet_WagesC(false),
    isSet_WagesI(false),
    isSet_ConsW(false),
	out_port_chgWorkersNW_WorkersNW(addOutputPort("out_port_chgWorkersNW_WorkersNW"))
{
}


Model &chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_WagesC) {
		WagesC = x;
		isSet_WagesC = true;
	}
	if(msg.port() == in_port_WagesI) {
		WagesI = x;
		isSet_WagesI = true;
	}
	if(msg.port() == in_port_ConsW) {
		ConsW = x;
		isSet_ConsW = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_WagesC & isSet_WagesI & isSet_ConsW ) {
	    Tuple<Real> out_value { ((WagesC+WagesI)-ConsW) };
		sendOutput(msg.time(), out_port_chgWorkersNW_WorkersNW, out_value);
	}
	
	return *this ;
}