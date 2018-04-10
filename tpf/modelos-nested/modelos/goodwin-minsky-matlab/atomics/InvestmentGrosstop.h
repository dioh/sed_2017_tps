#ifndef _InvestmentGrosstop_H_
#define _InvestmentGrosstop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVESTMENTGROSSTOP "InvestmentGrosstop"


class InvestmentGrosstop : public Atomic {
  public:
    
    InvestmentGrosstop(const string &name = INVESTMENTGROSSTOP );
    virtual string className() const {  return INVESTMENTGROSSTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_InvestmentFunctionReal;
    const Port &in_port_Output;
    Port &out_port_InvestmentGross;
    
    double InvestmentFunctionReal;
    double Output;
    bool isSet_InvestmentFunctionReal;
    bool isSet_Output;
};

#endif