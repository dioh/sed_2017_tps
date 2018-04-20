#ifndef _chgDepInvPlus_H_
#define _chgDepInvPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEPINVPLUS "chgDepInvPlus"


class chgDepInvPlus : public Atomic {
  public:
    
    chgDepInvPlus(const string &name = CHGDEPINVPLUS );
    virtual string className() const {  return CHGDEPINVPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Lend;
    const Port &ConstantBuy;
    const Port &Interest;
    const Port &Repay;
    const Port &WagesI;
    const Port &InvBuy;
    Port &out;
    

    double val_Lend;
    double val_ConstantBuy;
    double val_Interest;
    double val_Repay;
    double val_WagesI;
    double val_InvBuy;
    bool isSet_val_Lend;
    bool isSet_val_ConstantBuy;
    bool isSet_val_Interest;
    bool isSet_val_Repay;
    bool isSet_val_WagesI;
    bool isSet_val_InvBuy;
    
};

#endif