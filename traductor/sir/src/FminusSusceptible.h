#ifndef _FminusSusceptible_H_
#define _FminusSusceptible_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSSUSCEPTIBLE "FminusSusceptible"

class FminusSusceptible : public Atomic {
  public:
    
    FminusSusceptible(const string &name = FMINUSSUSCEPTIBLE );
    virtual string className() const {  return FMINUSSUSCEPTIBLE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inInfectiousIntegrator;
    const Port &inSusceptibleIntegrator;
    const Port &inTotalPopulation;
    const Port &inContactInfectivity;
    // Output ports
    Port &out;

    // State variables
    double infectiousIntegrator;
    double susceptibleIntegrator;
    double totalPopulation;
    double contactInfectivity;
    //
    // Check set of state variables
    bool isSetInfectiousIntegrator;
    bool isSetSusceptibleIntegrator;
    bool isSetTotalPopulation;
    bool isSetContactInfectivity;
    //
};

#endif