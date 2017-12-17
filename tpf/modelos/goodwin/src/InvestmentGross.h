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
    const Port &in_InvestmentFunctionReal;
    const Port &in_Output;
    Port &out;
    

    double InvestmentFunctionReal;
    double Output;
    bool isSet_InvestmentFunctionReal;
    bool isSet_Output;
    //
};

#endif