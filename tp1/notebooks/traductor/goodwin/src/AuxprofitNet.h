#ifndef _AuxprofitNet_H_
#define _AuxprofitNet_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXPROFITNET "AuxprofitNet"


class AuxprofitNet : public Atomic {
  public:
    
    AuxprofitNet(const string &name = AUXPROFITNET );
    virtual string className() const {  return AUXPROFITNET ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_profitGrossReal;
    const Port &in_interestPayments;
    // Output ports
    Port &out;

    // State variables
    double interestPayments;
    double profitGrossReal;
    //
    // Check set of state variables
    bool isSet_interestPayments;
    bool isSet_profitGrossReal;
    //
};

#endif