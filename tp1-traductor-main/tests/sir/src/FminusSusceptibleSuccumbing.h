#ifndef _FminusSusceptibleSuccumbing_H_
#define _FminusSusceptibleSuccumbing_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSSUSCEPTIBLESUCCUMBING "FminusSusceptibleSuccumbing"

class FminusSusceptibleSuccumbing : public Atomic {
  public:
    
    FminusSusceptibleSuccumbing(const string &name = FMINUSSUSCEPTIBLESUCCUMBING );
    virtual string className() const {  return FMINUSSUSCEPTIBLESUCCUMBING ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_susceptibleIntegrator;
    const Port &in_infectiousIntegrator;
    const Port &in_totalPopulation;
    const Port &in_contactInfectivity;
    // Output ports
    Port &out;

    // State variables
    double susceptibleIntegrator;
    double infectiousIntegrator;
    double totalPopulation;
    double contactInfectivity;
    //
    // Check set of state variables
    bool isSet_susceptibleIntegrator;
    bool isSet_infectiousIntegrator;
    bool isSet_totalPopulation;
    bool isSet_contactInfectivity;
    //
};

#endif