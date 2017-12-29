#include <random>
#include <string>
#include <vector>

#include "math.h"

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Conector.h"

using namespace std;

Conector::Conector(const string &name) :
    Atomic(name),
    in(addInputPort("in")),
    out(addOutputPort("out")),
    outValue(6)
{
}


Model &Conector::initFunction()
{
    holdIn(AtomicState::passive, VTime::Inf);
    return *this;
}


Model &Conector::externalFunction(const ExternalMessage &msg)
{
    outValue = Tuple<Real>::from_value(msg.value())[0].value();
    holdIn(AtomicState::active, VTime::Zero);
    return *this;
}


Model &Conector::internalFunction(const InternalMessage &)
{
    passivate();
    return *this ;
}


Model &Conector::outputFunction(const CollectMessage &msg)
{
    sendOutput(msg.time(), out, outValue);
    return *this ;
}