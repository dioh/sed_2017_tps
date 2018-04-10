#ifndef _TotPopulationDEVS_BASIC_COUPLED_Population_H_
#define _TotPopulationDEVS_BASIC_COUPLED_Population_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTPOPULATIONDEVS_BASIC_COUPLED_POPULATION "TotPopulationDEVS_BASIC_COUPLED_Population"

class TotPopulationDEVS_BASIC_COUPLED_Population : public Atomic {
  public:
    
    TotPopulationDEVS_BASIC_COUPLED_Population(const string &name = TOTPOPULATIONDEVS_BASIC_COUPLED_POPULATION );
    virtual string className() const {  return TOTPOPULATIONDEVS_BASIC_COUPLED_POPULATION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgPopulation_Population;
    
    Port &out_port_TotPopulation;

    double chgPopulation_Population;
    bool isSet_chgPopulation_Population;
    
    
};

#endif