#ifndef _TotPredatorDEVS_BASIC_COUPLED_Predator_H_
#define _TotPredatorDEVS_BASIC_COUPLED_Predator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTPREDATORDEVS_BASIC_COUPLED_PREDATOR "TotPredatorDEVS_BASIC_COUPLED_Predator"

class TotPredatorDEVS_BASIC_COUPLED_Predator : public Atomic {
  public:
    
    TotPredatorDEVS_BASIC_COUPLED_Predator(const string &name = TOTPREDATORDEVS_BASIC_COUPLED_PREDATOR );
    virtual string className() const {  return TOTPREDATORDEVS_BASIC_COUPLED_PREDATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_PlusPredator_Predator;
    const Port &in_minus_port_MinusPredator_Predator;
    
    Port &out_port_TotPredator;

    double PlusPredator_Predator;
    double MinusPredator_Predator;
    bool isSet_PlusPredator_Predator;
    
    bool isSet_MinusPredator_Predator;
    
};

#endif