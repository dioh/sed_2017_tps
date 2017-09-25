#ifndef _FplusSusc_H_
#define _FplusSusc_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FPLUSSUSC "FplusSusc"


class FplusSusc : public Atomic {
  public:
    
    FplusSusc(const string &name = FPLUSSUSC );
    virtual string className() const {  return FPLUSSUSC ;}
  
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
