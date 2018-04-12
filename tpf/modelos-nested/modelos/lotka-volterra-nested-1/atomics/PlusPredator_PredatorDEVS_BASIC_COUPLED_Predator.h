#ifndef _PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator_H_
#define _PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PLUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR "PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator"


class PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator : public Atomic {
  public:
    
    PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator(const string &name = PLUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR );
    virtual string className() const {  return PLUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Predator;
    const Port &in_port_Prey;
    const Port &in_port_paramD;
    Port &out_port_PlusPredator_Predator;
    
    double Predator;
    double Prey;
    double paramD;
    bool isSet_Predator;
    bool isSet_Prey;
    bool isSet_paramD;
};

#endif