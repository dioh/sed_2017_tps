#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "combinerPreySubSubModel.h"

using namespace std;

combinerPreySubSubModel::combinerPreySubSubModel(const string &name) :
	Atomic(name),
    Prey(addInputPort("Prey")),
    ctePulse(addInputPort("ctePulse")),
    isSet_Prey(false),
    isSet_ctePulse(false),
	combinerPreySubSubModel(addOutputPort("combinerPreySubSubModel"))
{
}


Model &combinerPreySubSubModel::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &combinerPreySubSubModel::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Prey) {
		Prey = x;
		isSet_Prey = true;
	}
	if(msg.port() == ctePulse) {
		ctePulse = x;
		isSet_ctePulse = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &combinerPreySubSubModel::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &combinerPreySubSubModel::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Prey & isSet_ctePulse ) {
	    Tuple<Real> out_value { ctePulse + Prey };
		sendOutput(msg.time(), combinerPreySubSubModel, out_value);
	}
	
	return *this ;
}