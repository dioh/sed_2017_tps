#ifndef _velocityOfMoney_H_
#define _velocityOfMoney_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define VELOCITYOFMONEY "velocityOfMoney"


class velocityOfMoney : public Atomic {
  public:
    
    velocityOfMoney(const string &name = VELOCITYOFMONEY );
    virtual string className() const {  return VELOCITYOFMONEY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &GDProduct;
    const Port &Money;
    Port &out;
    

    double val_GDProduct;
    double val_Money;
    bool isSet_val_GDProduct;
    bool isSet_val_Money;
    
};

#endif