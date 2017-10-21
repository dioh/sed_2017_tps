#ifndef _FminusLynx_H_
#define _FminusLynx_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSLYNX "FminusLynx"

class FminusLynx : public Atomic {
  public:
    
    FminusLynx(const string &name = FMINUSLYNX );
    virtual string className() const {  return FMINUSLYNX ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inLynx;
    const Port &inLynxDeathRate;
    // Output ports
    Port &out;

    // State variables
    double lynx;
    double lynxDeathRate;
    //
    // Check set of state variables
    bool isSetLynx;
    bool isSetLynxDeathRate;
    //
};

#endif