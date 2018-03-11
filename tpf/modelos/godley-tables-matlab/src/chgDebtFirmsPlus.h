#ifndef _chgDebtFirmsPlus_H_
#define _chgDebtFirmsPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEBTFIRMSPLUS "chgDebtFirmsPlus"


class chgDebtFirmsPlus : public Atomic {
  public:
    
    chgDebtFirmsPlus(const string &name = CHGDEBTFIRMSPLUS );
    virtual string className() const {  return CHGDEBTFIRMSPLUS ;}
  
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