#ifndef _FminusHares_H_
#define _FminusHares_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSHARES "FminusHares"

class FminusHares : public Atomic {
  public:
    
    FminusHares(const string &name = FMINUSHARES );
    virtual string className() const {  return FMINUSHARES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inHares;
    const Port &inLynx;
    const Port &inHareDeathRate;
    // Output ports
    Port &out;

    // State variables
    double hares;
    double lynx;
    double hareDeathRate;
    //
    // Check set of state variables
    bool isSetHares;
    bool isSetLynx;
    bool isSetHareDeathRate;
    //
};

#endif