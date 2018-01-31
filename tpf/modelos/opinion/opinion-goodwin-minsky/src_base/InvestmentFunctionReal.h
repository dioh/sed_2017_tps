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
    const Port &piR;
    const Port &piZ;
    const Port &piS;
    Port &out;
    

    double val_piR;
    double val_piZ;
    double val_piS;
    bool isSet_val_piR;
    bool isSet_val_piZ;
    bool isSet_val_piS;
    
};

#endif