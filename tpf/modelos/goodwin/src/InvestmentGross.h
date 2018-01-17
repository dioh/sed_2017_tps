#ifndef _InvestmentGross_H_
#define _InvestmentGross_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVESTMENTGROSS "InvestmentGross"


class InvestmentGross : public Atomic {
  public:
    
    InvestmentGross(const string &name = INVESTMENTGROSS );
    virtual string className() const {  return INVESTMENTGROSS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Profit;
    Port &out;
    

    double val_Profit;
    bool isSet_val_Profit;
    
};

#endif