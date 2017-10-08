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
    const Port &inSusceptible;
    const Port &inInfected;
    const Port &inContactInfectivity;
    const Port &inTotalPopulation;
    // Output ports
    Port &out;

    // State variables
    double susceptible;
    double infected;
    double contactInfectivity;
    double totalPopulation;
    //
    // Check set of state variables
    bool isSetSusceptible;
    bool isSetInfected;
    bool isSetContactInfectivity;
    bool isSetTotalPopulation;
    //
};

#endif