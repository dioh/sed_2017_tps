#ifndef _InvestmentFunctionRealtop_H_
#define _InvestmentFunctionRealtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVESTMENTFUNCTIONREALTOP "InvestmentFunctionRealtop"


class InvestmentFunctionRealtop : public Atomic {
  public:
    
    InvestmentFunctionRealtop(const string &name = INVESTMENTFUNCTIONREALTOP );
    virtual string className() const {  return INVESTMENTFUNCTIONREALTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_piR;
    const Port &in_port_piZ;
    const Port &in_port_piS;
    Port &out_port_InvestmentFunctionReal;
    
    double piR;
    double piZ;
    double piS;
    bool isSet_piR;
    bool isSet_piZ;
    bool isSet_piS;
};

#endif