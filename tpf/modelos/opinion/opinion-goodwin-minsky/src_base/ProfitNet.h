#ifndef _ProfitNet_H_
#define _ProfitNet_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFITNET "ProfitNet"


class ProfitNet : public Atomic {
  public:
    
    ProfitNet(const string &name = PROFITNET );
    virtual string className() const {  return PROFITNET ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &ProfitGrossReal;
    const Port &InterestPayments;
    Port &out;
    

    double val_ProfitGrossReal;
    double val_InterestPayments;
    bool isSet_val_ProfitGrossReal;
    bool isSet_val_InterestPayments;
    
};

#endif