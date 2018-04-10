#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "omegatop.h"

using namespace std;

omegatop::omegatop(const string &name) :
	Atomic(name),
    in_port_Wages(addInputPort("in_port_Wages")),
    in_port_Output(addInputPort("in_port_Output")),
    isSet_Wages(false),
    isSet_Output(false),
	out_port_omega(addOutputPort("out_port_omega"))
{
}


Model &omegatop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &omegatop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Wages) {
		Wages = x;
		isSet_Wages = true;
	}
	if(msg.port() == in_port_Output) {
		Output = x;
		isSet_Output = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &omegatop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &omegatop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Wages & isSet_Output ) {
	    Tuple<Real> out_value { (Wages/Output) };
		sendOutput(msg.time(), out_port_omega, out_value);
	}
	
	return *this ;
}