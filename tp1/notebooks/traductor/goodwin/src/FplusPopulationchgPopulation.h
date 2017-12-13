#ifndef _FplusPopulationchgPopulation_H_
#define _FplusPopulationchgPopulation_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPOPULATIONCHGPOPULATION "FplusPopulationchgPopulation"

class FplusPopulationchgPopulation : public Atomic {
  public:
    
    FplusPopulationchgPopulation(const string &name = FPLUSPOPULATIONCHGPOPULATION );
    virtual string className() const {  return FPLUSPOPULATIONCHGPOPULATION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_populationIntegrator;
    // Output ports
    Port &out;

    // State variables
    double populationIntegrator;
    //
    // Check set of state variables
    bool isSet_populationIntegrator;
    //
};

#endif