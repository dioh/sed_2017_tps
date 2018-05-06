#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "specialParamCtop.h"

using namespace std;

specialParamCtop::specialParamCtop(const string &name) :
	Atomic(name),
    in_port_PULSE_V_2_FP_2_I_2_specialParamC(addInputPort("in_port_PULSE_V_2_FP_2_I_2_specialParamC")),
    isSet_PULSE_V_2_FP_2_I_2_specialParamC(false),
	out_port_specialParamC(addOutputPort("out_port_specialParamC"))
{
}


Model &specialParamCtop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &specialParamCtop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_PULSE_V_2_FP_2_I_2_specialParamC) {
		PULSE_V_2_FP_2_I_2_specialParamC = x;
		isSet_PULSE_V_2_FP_2_I_2_specialParamC = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &specialParamCtop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &specialParamCtop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_PULSE_V_2_FP_2_I_2_specialParamC ) {
	    Tuple<Real> out_value { 0.3 - 0 * PULSE_V_2_FP_2_I_2_specialParamC };
		sendOutput(msg.time(), out_port_specialParamC, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_specialParamC, out_value);
	}
	
	return *this ;
}