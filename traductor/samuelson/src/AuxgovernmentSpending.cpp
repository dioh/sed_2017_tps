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
	in_steptime(addInputPort("in_steptime")),
	in_spendingstep(addInputPort("in_spendingstep")),
	in_basespending(addInputPort("in_basespending")),
	in_tIMESTEP1(addInputPort("in_tIMESTEP1")),
	isSet_steptime(false),
	isSet_spendingstep(false),
	isSet_basespending(false),
	isSet_tIMESTEP1(false),
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

	if(msg.port() == in_steptime) {
		steptime = x;
		isSet_steptime = true;
	}
	if(msg.port() == in_spendingstep) {
		spendingstep = x;
		isSet_spendingstep = true;
	}
	if(msg.port() == in_basespending) {
		basespending = x;
		isSet_basespending = true;
	}
	if(msg.port() == in_tIMESTEP1) {
		tIMESTEP1 = x;
		isSet_tIMESTEP1 = true;
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
	if( isSet_steptime & isSet_spendingstep & isSet_basespending & isSet_tIMESTEP1 ) {
		double val = basespending + spendingstep * ( steptime + tIMESTEP 1 );
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}