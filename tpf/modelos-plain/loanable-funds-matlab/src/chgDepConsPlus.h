#ifndef _chgDepConsPlus_H_
#define _chgDepConsPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEPCONSPLUS "chgDepConsPlus"


class chgDepConsPlus : public Atomic {
  public:
    
    chgDepConsPlus(const string &name = CHGDEPCONSPLUS );
    virtual string className() const {  return CHGDEPCONSPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Interest;
    const Port &Repay;
    const Port &InvBuy;
    const Port &ConsW;
    const Port &ConsB;
    const Port &Lend;
    const Port &IntFee;
    const Port &WagesC;
    const Port &ConstantBuy;
    Port &out;
    

    double val_Interest;
    double val_Repay;
    double val_InvBuy;
    double val_ConsW;
    double val_ConsB;
    double val_Lend;
    double val_IntFee;
    double val_WagesC;
    double val_ConstantBuy;
    bool isSet_val_Interest;
    bool isSet_val_Repay;
    bool isSet_val_InvBuy;
    bool isSet_val_ConsW;
    bool isSet_val_ConsB;
    bool isSet_val_Lend;
    bool isSet_val_IntFee;
    bool isSet_val_WagesC;
    bool isSet_val_ConstantBuy;
    
};

#endif