#ifndef _FplusWageRatechgWageRate_H_
#define _FplusWageRatechgWageRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSWAGERATECHGWAGERATE "FplusWageRatechgWageRate"

class FplusWageRatechgWageRate : public Atomic {
  public:
    
    FplusWageRatechgWageRate(const string &name = FPLUSWAGERATECHGWAGERATE );
    virtual string className() const {  return FPLUSWAGERATECHGWAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_wageFunction;
    const Port &in_wageRateIntegrator;
    // Output ports
    Port &out;

    // State variables
    double wageFunction;
    double wageRateIntegrator;
    //
    // Check set of state variables
    bool isSet_wageFunction;
    bool isSet_wageRateIntegrator;
    //
};

#endif