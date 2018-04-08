#ifndef _chgInvNWPlus_H_
#define _chgInvNWPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGINVNWPLUS "chgInvNWPlus"


class chgInvNWPlus : public Atomic {
  public:
    
    chgInvNWPlus(const string &name = CHGINVNWPLUS );
    virtual string className() const {  return CHGINVNWPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &ConstantBuy;
    const Port &Interest;
    const Port &WagesI;
    const Port &InvBuy;
    Port &out;
    

    double val_ConstantBuy;
    double val_Interest;
    double val_WagesI;
    double val_InvBuy;
    bool isSet_val_ConstantBuy;
    bool isSet_val_Interest;
    bool isSet_val_WagesI;
    bool isSet_val_InvBuy;
    
};

#endif