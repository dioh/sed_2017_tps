#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Labortop.h"

using namespace std;

Labortop::Labortop(const string &name) :
	Atomic(name),
    in_port_Output(addInputPort("in_port_Output")),
    in_port_LaborProductivity(addInputPort("in_port_LaborProductivity")),
    isSet_Output(false),
    isSet_LaborProductivity(false),
	out_port_Labor(addOutputPort("out_port_Labor"))
{
}


Model &Labortop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Labortop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Output) {
		Output = x;
		isSet_Output = true;
	}
	if(msg.port() == in_port_LaborProductivity) {
		LaborProductivity = x;
		isSet_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Labortop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Labortop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Output & isSet_LaborProductivity ) {
	    Tuple<Real> out_value { (Output/LaborProductivity) };
		sendOutput(msg.time(), out_port_Labor, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_Labor, out_value);
	}
	
	return *this ;
}