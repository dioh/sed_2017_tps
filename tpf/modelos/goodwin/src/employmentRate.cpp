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
	Labor(addInputPort("Labor")),
	Population(addInputPort("Population")),
	isSet_val_Labor(false),
	isSet_val_Population(false),
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

	if(msg.port() == Labor) {
		val_Labor = x;
		isSet_val_Labor = true;
	}
	if(msg.port() == Population) {
		val_Population = x;
		isSet_val_Population = true;
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
	if( isSet_val_Labor & isSet_val_Population ) {
		double val = val_Labor / val_Population;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}