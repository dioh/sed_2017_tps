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
    const Port &in_betaChgpopulationIntegrator;
    // Output ports
    Port &out;

    // State variables
    double populationIntegrator;
    double betaChgpopulationIntegrator;
    //
    // Check set of state variables
    bool isSet_populationIntegrator;
    bool isSet_betaChgpopulationIntegrator;
    //
};

#endif