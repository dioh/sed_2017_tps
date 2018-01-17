#ifndef _MinusPreyMinus_H_
#define _MinusPreyMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MINUSPREYMINUS "MinusPreyMinus"


class MinusPreyMinus : public Atomic {
  public:
    
    MinusPreyMinus(const string &name = MINUSPREYMINUS );
    virtual string className() const {  return MINUSPREYMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &paramB;
    const Port &Prey;
    const Port &Predator;
    Port &out;
    

    double val_paramB;
    double val_Prey;
    double val_Predator;
    bool isSet_val_paramB;
    bool isSet_val_Prey;
    bool isSet_val_Predator;
    
};

#endif