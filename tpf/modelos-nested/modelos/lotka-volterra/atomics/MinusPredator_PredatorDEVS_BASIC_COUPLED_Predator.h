#ifndef _MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator_H_
#define _MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MINUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR "MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator"


class MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator : public Atomic {
  public:
    
    MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator(const string &name = MINUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR );
    virtual string className() const {  return MINUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramC;
    const Port &in_port_Predator;
    Port &out_port_MinusPredator_Predator;
    
    double paramC;
    double Predator;
    bool isSet_paramC;
    bool isSet_Predator;
};

#endif