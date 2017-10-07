#ifndef _FplusHares_H_
#define _FplusHares_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FPLUSHARES "FplusHares"


class FplusHares : public Atomic {
  public:
    
    FplusHares(const string &name = FPLUSHARES );
    virtual string className() const {  return FPLUSHARES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inHares;
    const Port &inHareBirthRate;
    Port &out;

    double hares;
    bool isSetHares;
    
    double hareBirthRate;
    bool isSetHareBirthRate;
};

#endif
