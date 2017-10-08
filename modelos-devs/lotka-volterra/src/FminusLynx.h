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
    const Port &inLynx, &inLynxDeathRate;
    Port &out;

    double lynx;
    bool isSetLynx;

    double lynxDeathRate;
    bool isSetLynxDeathRate;
};

#endif
