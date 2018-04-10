#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "employmentRateValuetop.h"

using namespace std;

employmentRateValuetop::employmentRateValuetop(const string &name) :
	Atomic(name),
    in_port_Labor(addInputPort("in_port_Labor")),
    in_port_Population(addInputPort("in_port_Population")),
    isSet_Labor(false),
    isSet_Population(false),
	out_port_employmentRateValue(addOutputPort("out_port_employmentRateValue"))
{
}


Model &employmentRateValuetop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &employmentRateValuetop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_Labor) {
		Labor = x;
		isSet_Labor = true;
	}
	if(msg.port() == in_port_Population) {
		Population = x;
		isSet_Population = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &employmentRateValuetop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &employmentRateValuetop::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_Labor & isSet_Population ) {
	    Tuple<Real> out_value { (Labor/Population) };
		sendOutput(msg.time(), out_port_employmentRateValue, out_value);
	}
	
	return *this ;
}