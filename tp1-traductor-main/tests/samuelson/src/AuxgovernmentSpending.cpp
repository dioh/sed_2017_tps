#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxgovernmentSpending.h"

using namespace std;

AuxgovernmentSpending::AuxgovernmentSpending(const string &name) :
	Atomic(name),
	in_spendingstep(addInputPort("in_spendingstep")),
	in_basespending(addInputPort("in_basespending")),
	in_steptime,tIMESTEP1(addInputPort("in_steptime,tIMESTEP1")),
	in_PULSE(addInputPort("in_PULSE")),
	isSet_spendingstep(false),
	isSet_basespending(false),
	isSet_steptime,tIMESTEP1(false),
	isSet_PULSE(false),
	out(addOutputPort("out"))
{
}


Model &AuxgovernmentSpending::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxgovernmentSpending::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_spendingstep) {
		spendingstep = x;
		isSet_spendingstep = true;
	}
	if(msg.port() == in_basespending) {
		basespending = x;
		isSet_basespending = true;
	}
	if(msg.port() == in_steptime,tIMESTEP1) {
		steptime,tIMESTEP1 = x;
		isSet_steptime,tIMESTEP1 = true;
	}
	if(msg.port() == in_PULSE) {
		PULSE = x;
		isSet_PULSE = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxgovernmentSpending::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxgovernmentSpending::outputFunction(const CollectMessage &msg)
{
	if( isSet_spendingstep & isSet_basespending & isSet_steptime,tIMESTEP1 & isSet_PULSE ) {
		double val = basespending + spendingstep * PULSE( steptime, tIMESTEP 1);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}