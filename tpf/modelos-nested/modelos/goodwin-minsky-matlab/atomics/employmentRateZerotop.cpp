#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "employmentRateZerotop.h"

using namespace std;

employmentRateZerotop::employmentRateZerotop(const string &name) :
   	in_port_employmentRateZero(addInputPort("in_port_employmentRateZero")),
    out_port_employmentRateZero(addOutputPort("out_port_employmentRateZero")),
    employmentRateZero(-1),
    Atomic(name)
{
}


Model &employmentRateZerotop::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &employmentRateZerotop::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].	value();
    if(msg.port() == in_port_employmentRateZero) {
    	employmentRateZero = x;
    }
    holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &employmentRateZerotop::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &employmentRateZerotop::outputFunction(const CollectMessage &msg)
{
    Tuple<Real> out_value { employmentRateZero };
	sendOutput(msg.time(),  out_port_employmentRateZero, out_value);
    return *this ;
}