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
    const Port &inHares, &inLynx;
    const Port &inHareDeathRate;
    Port &out;

    double hares, lynx;
    bool isSetHares, isSetLynx;
    
    double hareDeathRate;
    bool isSetHareDeathRate;
};

#endif
