#ifndef _InterestPayments_H_
#define _InterestPayments_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTERESTPAYMENTS "InterestPayments"


class InterestPayments : public Atomic {
  public:
    
    InterestPayments(const string &name = INTERESTPAYMENTS );
    virtual string className() const {  return INTERESTPAYMENTS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Debt;
    const Port &rateInterestOnLoans;
    Port &out;
    

    double val_Debt;
    double val_rateInterestOnLoans;
    bool isSet_val_Debt;
    bool isSet_val_rateInterestOnLoans;
    
};

#endif