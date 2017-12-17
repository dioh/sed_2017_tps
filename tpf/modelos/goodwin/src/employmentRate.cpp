#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "employmentRate.h"

using namespace std;

employmentRate::employmentRate(const string &name) :
	Atomic(name),
	in_Labor(addInputPort("in_Labor")),
	in_Population(addInputPort("in_Population")),
	isSet_Labor(false),
	isSet_Population(false),
	out(addOutputPort("out"))
{
}


Model &employmentRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &employmentRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_Labor) {
		Labor = x;
		isSet_Labor = true;
	}
	if(msg.port() == in_Population) {
		Population = x;
		isSet_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &employmentRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &employmentRate::outputFunction(const CollectMessage &msg)
{
	if( isSet_Labor & isSet_Population ) {
		double val = Labor / Population;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}