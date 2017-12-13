#ifndef _FplusPreyPlusPrey_H_
#define _FplusPreyPlusPrey_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPREYPLUSPREY "FplusPreyPlusPrey"

class FplusPreyPlusPrey : public Atomic {
  public:
    
    FplusPreyPlusPrey(const string &name = FPLUSPREYPLUSPREY );
    virtual string className() const {  return FPLUSPREYPLUSPREY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_preyIntegrator;
    // Output ports
    Port &out;

    // State variables
    double preyIntegrator;
    //
    // Check set of state variables
    bool isSet_preyIntegrator;
    //
};

#endif