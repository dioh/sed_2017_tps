#ifndef _AuxinterestPayments_H_
#define _AuxinterestPayments_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXINTERESTPAYMENTS "AuxinterestPayments"


class AuxinterestPayments : public Atomic {
  public:
    
    AuxinterestPayments(const string &name = AUXINTERESTPAYMENTS );
    virtual string className() const {  return AUXINTERESTPAYMENTS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_debtIntegrator;
    const Port &in_rateInterestOnLoans;
    // Output ports
    Port &out;

    // State variables
    double debtIntegrator;
    double rateInterestOnLoans;
    //
    // Check set of state variables
    bool isSet_debtIntegrator;
    bool isSet_rateInterestOnLoans;
    //
};

#endif