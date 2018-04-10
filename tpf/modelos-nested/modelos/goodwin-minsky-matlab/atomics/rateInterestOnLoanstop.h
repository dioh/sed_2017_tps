#ifndef _rateInterestOnLoanstop_H_
#define _rateInterestOnLoanstop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATEINTERESTONLOANSTOP "rateInterestOnLoanstop"


class rateInterestOnLoanstop : public Atomic {
  public:
    
    rateInterestOnLoanstop(const string &name = RATEINTERESTONLOANSTOP );
    virtual string className() const {  return RATEINTERESTONLOANSTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_rateInterestOnLoans;
    
    Port &out_port_rateInterestOnLoans;
    
    double rateInterestOnLoans;
    };

#endif