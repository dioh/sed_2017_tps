#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Labor.h"

using namespace std;

Labor::Labor(const string &name) :
	Atomic(name),
	in_Output(addInputPort("in_Output")),
	in_LaborProductivity(addInputPort("in_LaborProductivity")),
	isSet_Output(false),
	isSet_LaborProductivity(false),
	out(addOutputPort("out"))
{
}


Model &Labor::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Labor::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Output) {
		Output = x;
		isSet_Output = true;
	}
	if(msg.port() == in_LaborProductivity) {
		LaborProductivity = x;
		isSet_LaborProductivity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Labor::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Labor::outputFunction(const CollectMessage &msg)
{
	if( isSet_Output & isSet_LaborProductivity ) {
		double val = Output / LaborProductivity;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}