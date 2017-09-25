#ifndef _FminusRecov_H_
#define _FminusRecov_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FMINUSRECOV "FminusRecov"


class FminusRecov : public Atomic {
  public:
    
    FminusRecov(const string &name = FMINUSRECOV );
    virtual string className() const {  return FMINUSRECOV ;}
  
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
