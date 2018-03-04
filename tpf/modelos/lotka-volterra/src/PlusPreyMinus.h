#ifndef _PlusPreyMinus_H_
#define _PlusPreyMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PLUSPREYMINUS "PlusPreyMinus"


class PlusPreyMinus : public Atomic {
  public:
    
    PlusPreyMinus(const string &name = PLUSPREYMINUS );
    virtual string className() const {  return PLUSPREYMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &paramA;
    const Port &Prey;
    Port &out;
    

    double val_paramA;
    double val_Prey;
    bool isSet_val_paramA;
    bool isSet_val_Prey;
    
};

#endif