#ifndef _chgDebtFirmsMinus_H_
#define _chgDebtFirmsMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEBTFIRMSMINUS "chgDebtFirmsMinus"


class chgDebtFirmsMinus : public Atomic {
  public:
    
    chgDebtFirmsMinus(const string &name = CHGDEBTFIRMSMINUS );
    virtual string className() const {  return CHGDEBTFIRMSMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &LendF;
    const Port &RepayF;
    Port &out;
    

    double val_LendF;
    double val_RepayF;
    bool isSet_val_LendF;
    bool isSet_val_RepayF;
    
};

#endif