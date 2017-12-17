#ifndef _fp_Capital_chgCapital_H_
#define _fp_Capital_chgCapital_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_CAPITAL_CHGCAPITAL "fp_Capital_chgCapital"

class fp_Capital_chgCapital : public Atomic {
  public:
    fp_Capital_chgCapital(const string &name = FP_CAPITAL_CHGCAPITAL );
    virtual string className() const {  return FP_CAPITAL_CHGCAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_InvestmentNetReal;
    Port &out;
    

    double InvestmentNetReal;
    bool isSet_InvestmentNetReal;
    //
};

#endif