#ifndef _populationDeath_hunterDEVS_BASIC_COUPLED_hunter_H_
#define _populationDeath_hunterDEVS_BASIC_COUPLED_hunter_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define POPULATIONDEATH_HUNTERDEVS_BASIC_COUPLED_HUNTER "populationDeath_hunterDEVS_BASIC_COUPLED_hunter"


class populationDeath_hunterDEVS_BASIC_COUPLED_hunter : public Atomic {
  public:
    
    populationDeath_hunterDEVS_BASIC_COUPLED_hunter(const string &name = POPULATIONDEATH_HUNTERDEVS_BASIC_COUPLED_HUNTER );
    virtual string className() const {  return POPULATIONDEATH_HUNTERDEVS_BASIC_COUPLED_HUNTER ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &hunter;
    Port &populationDeath_hunter;
    
    double hunter;
    bool isSet_hunter;
};

#endif