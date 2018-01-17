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
    inShockCriteria(addInputPort("inShockCriteria")),
    isSet_ShockCriteria(false),
    isSet_Degenerates(false),
    isSet_Neutralists(false),
    isSet_RationalSupporters(false),
    prev_RationalSupporters(0),
    prev_Neutralists(0),
    prev_Degenerates(0),
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
    if( isSet_ShockCriteria && isSet_Neutralists && isSet_Degenerates && isSet_RationalSupporters) {

        // Funcion que determina si activar o no activar los shockers

        if(ShockCriteria == 1) {
            // Regla : envio shocks negativo / negativo / neutro / positivo , segun se rompen los limites 80 / 60 / 40 / 20 para Neutralists
            if (prev_Neutralists > 80 && Neutralists < 80) {
                double val = 5.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out0, outValue);
            }
            if (prev_Neutralists > 60 && Neutralists < 60) {
                double val = 5.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out1, outValue);
            }
            if (prev_Neutralists > 40 && Neutralists < 40) {
                double val = 6.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out2, outValue);
            }
            if (prev_Neutralists > 20 && Neutralists < 20) {
                double val = 7.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv); 
                sendOutput(msg.time(), out3, outValue);
            }
        } else if(ShockCriteria == 2) {
            // Regla : envio shocks neutro / positivo / neutro / negativo , segun se rompen los limites 80 / 60 / 40 / 20 para Neutralists
            if (prev_Neutralists > 80 && Neutralists < 80) {
                double val = 6.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out0, outValue);
            }
            if (prev_Neutralists > 60 && Neutralists < 60) {
                double val = 7.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out1, outValue);
            }
            if (prev_Neutralists > 40 && Neutralists < 40) {
                double val = 6.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv);
                sendOutput(msg.time(), out2, outValue);
            }
            if (prev_Neutralists > 20 && Neutralists < 20) {
                double val = 5.0; std::vector<Real> tv; tv.push_back(Real(val));
                Tuple<Real> outValue = Tuple<Real>(&tv); 
                sendOutput(msg.time(), out3, outValue);
            }
        }
    }
    return *this ;
}