#ifndef _chgFirmsPlus_H_
#define _chgFirmsPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGFIRMSPLUS "chgFirmsPlus"


class chgFirmsPlus : public Atomic {
  public:
    
    chgFirmsPlus(const string &name = CHGFIRMSPLUS );
    virtual string className() const {  return CHGFIRMSPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &LendF;
    const Port &ConsW;
    const Port &ConsB;
    const Port &Interest;
    const Port &Wages;
    const Port &RepayF;
    Port &out;
    

    double val_LendF;
    double val_ConsW;
    double val_ConsB;
    double val_Interest;
    double val_Wages;
    double val_RepayF;
    bool isSet_val_LendF;
    bool isSet_val_ConsW;
    bool isSet_val_ConsB;
    bool isSet_val_Interest;
    bool isSet_val_Wages;
    bool isSet_val_RepayF;
    
};

#endif