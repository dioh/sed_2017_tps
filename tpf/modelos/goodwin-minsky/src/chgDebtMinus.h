#ifndef _chgDebtMinus_H_
#define _chgDebtMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEBTMINUS "chgDebtMinus"


class chgDebtMinus : public Atomic {
  public:
    
    chgDebtMinus(const string &name = CHGDEBTMINUS );
    virtual string className() const {  return CHGDEBTMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &InvestmentGross;
    Port &out;
    

    double val_InvestmentGross;
    bool isSet_val_InvestmentGross;
    
};

#endif