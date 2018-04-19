#ifndef _TotPopulation_H_
#define _TotPopulation_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTPOPULATION "TotPopulation"

class TotPopulation : public Atomic {
  public:
    
    TotPopulation(const string &name = TOTPOPULATION );
    virtual string className() const {  return TOTPOPULATION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population;
    
    Port &out_port_TotPopulation;

    double chgPopulation_PopulationDEVS_BASIC_COUPLED_Population;
    bool isSet_chgPopulation_PopulationDEVS_BASIC_COUPLED_Population;
    
    
};

#endif