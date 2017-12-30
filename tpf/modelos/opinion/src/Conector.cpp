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
    inRationalSupporters(addInputPort("inRationalSupporters")),
    inDegenerates(addInputPort("inDegenerates")),
    inNeutralists(addInputPort("inNeutralists")),
    isSet_Degenerates(false),
    isSet_Neutralists(false),
    isSet_RationalSupporters(false),
    prev_RationalSupporters(0),
    prev_Neutralists(0),
    prev_Degenerates(0),
    out(addOutputPort("out"))
{
}


Model &Conector::initFunction()
{
    holdIn(AtomicState::passive, VTime::Inf);
    return *this;
}


Model &Conector::externalFunction(const ExternalMessage &msg)
{
    double x = Tuple<Real>::from_value(msg.value())[0].value();

    if(msg.port() == inRationalSupporters) {
        prev_RationalSupporters = RationalSupporters;
        RationalSupporters = x;
        isSet_RationalSupporters = true;
    }
    if(msg.port() == inDegenerates) {
        prev_Degenerates = Degenerates;
        Degenerates = x;
        isSet_Degenerates = true;
    }
    if(msg.port() == inNeutralists) {
        prev_Neutralists = Neutralists;
        Neutralists = x;
        isSet_Neutralists = true;
    }

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
    if( isSet_Neutralists && isSet_Degenerates && isSet_RationalSupporters) {

        double outValue = 0;
        // Funcion que determina si activar o no activar los shockers
        if (prev_Neutralists > 20 && Neutralists < 20) {
            outValue = 3; // Shock positivo
        }

        // Output
        if (outValue > 0) {
            sendOutput(msg.time(), out, outValue);
        }
    }
    return *this ;
}