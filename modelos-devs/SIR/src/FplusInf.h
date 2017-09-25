#ifndef _FplusInf_H_
#define _FplusInf_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FPLUSINF "FplusInf"


class FplusInf : public Atomic {
  public:
    
    FplusInf(const string &name = FPLUSINF );
    virtual string className() const {  return FPLUSINF ;}
  
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
