#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "paramEtop.h"

using namespace std;

paramEtop::paramEtop(const string &name) :
	Atomic(name),
    in_port_paramB(addInputPort("in_port_paramB")),
    in_port_PULSE_V_1_FP_1_I_1(addInputPort("in_port_PULSE_V_1_FP_1_I_1")),
    in_port_paramA(addInputPort("in_port_paramA")),
    isSet_paramB(false),
    isSet_PULSE_V_1_FP_1_I_1(false),
    isSet_paramA(false),
	out_port_paramE(addOutputPort("out_port_paramE"))
{
}


Model &paramEtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &paramEtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_paramB) {
		paramB = x;
		isSet_paramB = true;
	}
	if(msg.port() == in_port_PULSE_V_1_FP_1_I_1) {
		PULSE_V_1_FP_1_I_1 = x;
		isSet_PULSE_V_1_FP_1_I_1 = true;
	}
	if(msg.port() == in_port_paramA) {
		paramA = x;
		isSet_paramA = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &paramEtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &paramEtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_paramB & isSet_PULSE_V_1_FP_1_I_1 & isSet_paramA ) {
	    Tuple<Real> out_value { paramA + paramB + 0 * PULSE_V_1_FP_1_I_1 };
		sendOutput(msg.time(), out_port_paramE, out_value);
	}
	
	return *this ;
}