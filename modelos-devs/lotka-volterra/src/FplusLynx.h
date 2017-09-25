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
    const Port &inVar1, &inVar2;
    Port &out;

    double val;
    double var1, var2;
};

#endif
