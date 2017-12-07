#ifndef _FplusInvestmentinflow_H_
#define _FplusInvestmentinflow_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSINVESTMENTINFLOW "FplusInvestmentinflow"

class FplusInvestmentinflow : public Atomic {
  public:
    
    FplusInvestmentinflow(const string &name = FPLUSINVESTMENTINFLOW );
    virtual string className() const {  return FPLUSINVESTMENTINFLOW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_constant;
    // Output ports
    Port &out;

    // State variables
    double constant;
    //
    // Check set of state variables
    bool isSet_constant;
    //
};

#endif