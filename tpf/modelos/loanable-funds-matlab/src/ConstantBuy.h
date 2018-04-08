#ifndef _ConstantBuy_H_
#define _ConstantBuy_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CONSTANTBUY "ConstantBuy"


class ConstantBuy : public Atomic {
  public:
    
    ConstantBuy(const string &name = CONSTANTBUY );
    virtual string className() const {  return CONSTANTBUY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &PiCG;
    const Port &CPIValue;
    Port &out;
    

    double val_PiCG;
    double val_CPIValue;
    bool isSet_val_PiCG;
    bool isSet_val_CPIValue;
    
};

#endif