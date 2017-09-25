#ifndef _FplusRecov_H_
#define _FplusRecov_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FPLUSRECOV "FplusRecov"


class FplusRecov : public Atomic {
  public:
    
    FplusRecov(const string &name = FPLUSRECOV );
    virtual string className() const {  return FPLUSRECOV ;}
  
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
