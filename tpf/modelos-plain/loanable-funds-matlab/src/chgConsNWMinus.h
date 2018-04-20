#ifndef _chgConsNWMinus_H_
#define _chgConsNWMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGCONSNWMINUS "chgConsNWMinus"


class chgConsNWMinus : public Atomic {
  public:
    
    chgConsNWMinus(const string &name = CHGCONSNWMINUS );
    virtual string className() const {  return CHGCONSNWMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Interest;
    const Port &InvBuy;
    const Port &ConsW;
    const Port &ConsB;
    const Port &IntFee;
    const Port &WagesC;
    const Port &ConstantBuy;
    Port &out;
    

    double val_Interest;
    double val_InvBuy;
    double val_ConsW;
    double val_ConsB;
    double val_IntFee;
    double val_WagesC;
    double val_ConstantBuy;
    bool isSet_val_Interest;
    bool isSet_val_InvBuy;
    bool isSet_val_ConsW;
    bool isSet_val_ConsB;
    bool isSet_val_IntFee;
    bool isSet_val_WagesC;
    bool isSet_val_ConstantBuy;
    
};

#endif