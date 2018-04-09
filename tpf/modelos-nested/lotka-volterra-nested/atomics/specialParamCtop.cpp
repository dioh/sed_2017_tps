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
    PULSE_V_2_FP_2_I_2(addInputPort("PULSE_V_2_FP_2_I_2")),
    isSet_PULSE_V_2_FP_2_I_2(false),
	specialParamCtop(addOutputPort("specialParamCtop"))
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

	if(msg.port() == PULSE_V_2_FP_2_I_2) {
		PULSE_V_2_FP_2_I_2 = x;
		isSet_PULSE_V_2_FP_2_I_2 = true;
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
	
	if( isSet_PULSE_V_2_FP_2_I_2 ) {
	    Tuple<Real> out_value { 0.3 - 0 * PULSE_V_2_FP_2_I_2 };
		sendOutput(msg.time(), specialParamCtop, out_value);
	}
	
	return *this ;
}