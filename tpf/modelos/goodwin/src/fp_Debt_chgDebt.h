#ifndef _fp_Debt_chgDebt_H_
#define _fp_Debt_chgDebt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_DEBT_CHGDEBT "fp_Debt_chgDebt"

class fp_Debt_chgDebt : public Atomic {
  public:
    fp_Debt_chgDebt(const string &name = FP_DEBT_CHGDEBT );
    virtual string className() const {  return FP_DEBT_CHGDEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_InvestmentGross;
    Port &out;
    

    double InvestmentGross;
    bool isSet_InvestmentGross;
    //
};

#endif