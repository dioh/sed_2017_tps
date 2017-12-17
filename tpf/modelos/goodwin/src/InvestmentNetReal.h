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
    const Port &in_InvestmentGross;
    const Port &in_Capital;
    const Port &in_deltaKReal;
    Port &out;
    

    double InvestmentGross;
    double Capital;
    double deltaKReal;
    bool isSet_InvestmentGross;
    bool isSet_Capital;
    bool isSet_deltaKReal;
    //
};

#endif