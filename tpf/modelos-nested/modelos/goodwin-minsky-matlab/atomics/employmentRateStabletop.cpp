#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "employmentRateStabletop.h"

using namespace std;

employmentRateStabletop::employmentRateStabletop(const string &name) :
   	in_port_employmentRateStable(addInputPort("in_port_employmentRateStable")),
    out_port_employmentRateStable(addOutputPort("out_port_employmentRateStable")),
    employmentRateStable(-1),
    Atomic(name)
{
}


Model &employmentRateStabletop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &employmentRateStabletop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_employmentRateStable) {
    	employmentRateStable = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &employmentRateStabletop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &employmentRateStabletop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { employmentRateStable };
	sendOutput(msg.time(),  out_port_employmentRateStable, out_value);
    return *this ;
}