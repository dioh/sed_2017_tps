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
    const Port &in_Debt;
    const Port &in_rateInterestOnLoans;
    Port &out;
    

    double Debt;
    double rateInterestOnLoans;
    bool isSet_Debt;
    bool isSet_rateInterestOnLoans;
    //
};

#endif