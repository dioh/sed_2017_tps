#ifndef _InvestmentNetRealtop_H_
#define _InvestmentNetRealtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVESTMENTNETREALTOP "InvestmentNetRealtop"


class InvestmentNetRealtop : public Atomic {
  public:
    
    InvestmentNetRealtop(const string &name = INVESTMENTNETREALTOP );
    virtual string className() const {  return INVESTMENTNETREALTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_InvestmentGross;
    const Port &in_port_deltaKReal;
    const Port &in_port_Capital;
    Port &out_port_InvestmentNetReal;
    
    double InvestmentGross;
    double deltaKReal;
    double Capital;
    bool isSet_InvestmentGross;
    bool isSet_deltaKReal;
    bool isSet_Capital;
};

#endif