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
    const Port &in_ProfitGrossReal;
    const Port &in_InterestPayments;
    Port &out;
    

    double ProfitGrossReal;
    double InterestPayments;
    bool isSet_ProfitGrossReal;
    bool isSet_InterestPayments;
    //
};

#endif