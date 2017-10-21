#ifndef _FminusInfectious_H_
#define _FminusInfectious_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSINFECTIOUS "FminusInfectious"

class FminusInfectious : public Atomic {
  public:
    
    FminusInfectious(const string &name = FMINUSINFECTIOUS );
    virtual string className() const {  return FMINUSINFECTIOUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inInfectiousIntegrator;
    const Port &inDuration;
    // Output ports
    Port &out;

    // State variables
    double infectiousIntegrator;
    double duration;
    //
    // Check set of state variables
    bool isSetInfectiousIntegrator;
    bool isSetDuration;
    //
};

#endif