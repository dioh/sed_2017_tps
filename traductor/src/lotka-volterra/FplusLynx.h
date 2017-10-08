#ifndef _FplusLynx_H_
#define _FplusLynx_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSLYNX "FplusLynx"

class FplusLynx : public Atomic {
  public:
    
    FplusLynx(const string &name = FPLUSLYNX );
    virtual string className() const {  return FPLUSLYNX ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inLynx;
    const Port &inHares;
    const Port &inLynxBirthRate;
    // Output ports
    Port &out;

    // State variables
    double lynx;
    double hares;
    double lynxBirthRate;
    //
    // Check set of state variables
    bool isSetLynx;
    bool isSetHares;
    bool isSetLynxBirthRate;
    //
};

#endif