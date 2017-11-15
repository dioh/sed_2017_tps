#ifndef _FplusRecoveredRecovering_H_
#define _FplusRecoveredRecovering_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSRECOVEREDRECOVERING "FplusRecoveredRecovering"

class FplusRecoveredRecovering : public Atomic {
  public:
    
    FplusRecoveredRecovering(const string &name = FPLUSRECOVEREDRECOVERING );
    virtual string className() const {  return FPLUSRECOVEREDRECOVERING ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_infectiousIntegrator;
    const Port &in_duration;
    // Output ports
    Port &out;

    // State variables
    double infectiousIntegrator;
    double duration;
    //
    // Check set of state variables
    bool isSet_infectiousIntegrator;
    bool isSet_duration;
    //
};

#endif