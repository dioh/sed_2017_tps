#ifndef _chgDebtPlus_H_
#define _chgDebtPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEBTPLUS "chgDebtPlus"


class chgDebtPlus : public Atomic {
  public:
    
    chgDebtPlus(const string &name = CHGDEBTPLUS );
    virtual string className() const {  return CHGDEBTPLUS ;}
  
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