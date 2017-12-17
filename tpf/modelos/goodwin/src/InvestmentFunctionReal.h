#ifndef _InvestmentFunctionReal_H_
#define _InvestmentFunctionReal_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVESTMENTFUNCTIONREAL "InvestmentFunctionReal"


class InvestmentFunctionReal : public Atomic {
  public:
    
    InvestmentFunctionReal(const string &name = INVESTMENTFUNCTIONREAL );
    virtual string className() const {  return INVESTMENTFUNCTIONREAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_piR;
    const Port &in_piZ;
    const Port &in_piS;
    Port &out;
    

    double piR;
    double piZ;
    double piS;
    bool isSet_piR;
    bool isSet_piZ;
    bool isSet_piS;
    //
};

#endif