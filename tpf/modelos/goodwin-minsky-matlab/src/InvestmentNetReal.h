#ifndef _InvestmentNetReal_H_
#define _InvestmentNetReal_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVESTMENTNETREAL "InvestmentNetReal"


class InvestmentNetReal : public Atomic {
  public:
    
    InvestmentNetReal(const string &name = INVESTMENTNETREAL );
    virtual string className() const {  return INVESTMENTNETREAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &InvestmentGross;
    const Port &Capital;
    const Port &deltaKReal;
    Port &out;
    

    double val_InvestmentGross;
    double val_Capital;
    double val_deltaKReal;
    bool isSet_val_InvestmentGross;
    bool isSet_val_Capital;
    bool isSet_val_deltaKReal;
    
};

#endif