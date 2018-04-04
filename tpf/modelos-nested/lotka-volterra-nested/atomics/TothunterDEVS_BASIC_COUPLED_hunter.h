#ifndef _TothunterDEVS_BASIC_COUPLED_hunter_H_
#define _TothunterDEVS_BASIC_COUPLED_hunter_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTHUNTERDEVS_BASIC_COUPLED_HUNTER "TothunterDEVS_BASIC_COUPLED_hunter"

class TothunterDEVS_BASIC_COUPLED_hunter : public Atomic {
  public:
    
    TothunterDEVS_BASIC_COUPLED_hunter(const string &name = TOTHUNTERDEVS_BASIC_COUPLED_HUNTER );
    virtual string className() const {  return TOTHUNTERDEVS_BASIC_COUPLED_HUNTER ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &populationGrowth_hunter;
    const Port &populationDeath_hunter;
    

    double populationGrowth_hunter;
    double populationDeath_hunter;
    bool isSet_populationGrowth_hunter;
    
    bool isSet_populationDeath_hunter;
    
};

#endif