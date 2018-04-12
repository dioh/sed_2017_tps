#ifndef _chgPopulation_PopulationDEVS_BASIC_COUPLED_Population_H_
#define _chgPopulation_PopulationDEVS_BASIC_COUPLED_Population_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGPOPULATION_POPULATIONDEVS_BASIC_COUPLED_POPULATION "chgPopulation_PopulationDEVS_BASIC_COUPLED_Population"


class chgPopulation_PopulationDEVS_BASIC_COUPLED_Population : public Atomic {
  public:
    
    chgPopulation_PopulationDEVS_BASIC_COUPLED_Population(const string &name = CHGPOPULATION_POPULATIONDEVS_BASIC_COUPLED_POPULATION );
    virtual string className() const {  return CHGPOPULATION_POPULATIONDEVS_BASIC_COUPLED_POPULATION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Betaa;
    const Port &in_port_Population;
    Port &out_port_chgPopulation_Population;
    
    double Betaa;
    double Population;
    bool isSet_Betaa;
    bool isSet_Population;
};

#endif