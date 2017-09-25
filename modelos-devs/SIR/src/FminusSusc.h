#ifndef _FminusSusc_H_
#define _FminusSusc_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FMINUSSUSC "FminusSusc"


class FminusSusc : public Atomic {
  public:
    
    FminusSusc(const string &name = FMINUSSUSC );
    virtual string className() const {  return FMINUSSUSC ;}
  
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
