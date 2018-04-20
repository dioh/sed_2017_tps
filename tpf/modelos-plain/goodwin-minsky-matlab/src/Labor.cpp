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
	Output(addInputPort("Output")),
	LaborProductivity(addInputPort("LaborProductivity")),
	isSet_val_Output(false),
	isSet_val_LaborProductivity(false),
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

	if(msg.port() == Output) {
		val_Output = x;
		isSet_val_Output = true;
	}
	if(msg.port() == LaborProductivity) {
		val_LaborProductivity = x;
		isSet_val_LaborProductivity = true;
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
	if( isSet_val_Output & isSet_val_LaborProductivity ) {
		double val = (val_Output/val_LaborProductivity);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}