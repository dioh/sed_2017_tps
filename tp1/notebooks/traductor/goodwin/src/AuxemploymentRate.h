#ifndef _AuxemploymentRate_H_
#define _AuxemploymentRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXEMPLOYMENTRATE "AuxemploymentRate"


class AuxemploymentRate : public Atomic {
  public:
    
    AuxemploymentRate(const string &name = AUXEMPLOYMENTRATE );
    virtual string className() const {  return AUXEMPLOYMENTRATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_labor;
    const Port &in_populationIntegrator;
    // Output ports
    Port &out;

    // State variables
    double populationIntegrator;
    double labor;
    //
    // Check set of state variables
    bool isSet_populationIntegrator;
    bool isSet_labor;
    //
};

#endif