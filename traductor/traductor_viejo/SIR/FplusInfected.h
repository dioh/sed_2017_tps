#ifndef _FplusInfected_H_
#define _FplusInfected_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSINFECTED "FplusInfected"

class FplusInfected : public Atomic {
  public:
    
    FplusInfected(const string &name = FPLUSINFECTED );
    virtual string className() const {  return FPLUSINFECTED ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inInfected;
    const Port &inSusceptible;
    const Port &inContactInfectivity;
    const Port &inTotalPopulation;
    // Output ports
    Port &out;

    // State variables
    double infected;
    double susceptible;
    double contactInfectivity;
    double totalPopulation;
    //
    // Check set of state variables
    bool isSetInfected;
    bool isSetSusceptible;
    bool isSetContactInfectivity;
    bool isSetTotalPopulation;
    //
};

#endif