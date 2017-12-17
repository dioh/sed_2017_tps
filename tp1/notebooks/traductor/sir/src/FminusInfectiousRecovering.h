#ifndef _FminusInfectiousRecovering_H_
#define _FminusInfectiousRecovering_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSINFECTIOUSRECOVERING "FminusInfectiousRecovering"

class FminusInfectiousRecovering : public Atomic {
  public:
    
    FminusInfectiousRecovering(const string &name = FMINUSINFECTIOUSRECOVERING );
    virtual string className() const {  return FMINUSINFECTIOUSRECOVERING ;}
  
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