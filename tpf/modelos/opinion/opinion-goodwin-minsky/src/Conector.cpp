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
    inShockCriteria(addInputPort("inShockCriteria")),
    isSet_ShockCriteria(false),
    inLaborProductivity(addInputPort("inLaborProductivity")),
    inWageRate(addInputPort("inWageRate")),
    inDebt(addInputPort("inDebt")),
    inPopulation(addInputPort("inPopulation")),
    inCapital(addInputPort("inCapital")),
    isSet_LaborProductivity(false),
    isSet_WageRate(false),
    isSet_Debt(false),
    isSet_Population(false),
    isSet_Capital(false),
    prev_LaborProductivity(0),
    prev_WageRate(0),
    prev_Debt(0),
    prev_Population(0),
    prev_Capital(0),
    out0(addOutputPort("out0")),
    out1(addOutputPort("out1")),
    out2(addOutputPort("out2")),
    out3(addOutputPort("out3")),
    out4(addOutputPort("out4"))
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
    
    if(msg.port() == inShockCriteria) {
        ShockCriteria = x;
        isSet_ShockCriteria = true;
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
    if( isSet_ShockCriteria ) {

        // Funcion que determina si activar o no activar los shockers

        if(ShockCriteria == 1) {
            // Regla : envio shocks negativo / negativo / negativo / negativo , segun se rompen los limites 80 / 60 / 40 / 20 para Neutralists
            if (true) {
                double val = 7.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out0, outValue);
                sendOutput(msg.time(), out1, outValue);
                sendOutput(msg.time(), out2, outValue);
                sendOutput(msg.time(), out3, outValue);
                sendOutput(msg.time(), out4, outValue);
            }
        } else if(ShockCriteria == 2) {
            // Regla : envio shocks 2
            // TODO : aca no hago nada
        }
    }
    return *this ;
}