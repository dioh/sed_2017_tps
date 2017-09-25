#ifndef _Fplus_H_
#define _Fplus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FPLUS "Fplus"


class Fplus : public Atomic {
  public:
    
    Fplus(const string &name = FPLUS );
    virtual string className() const {  return FPLUS ;}
  
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
