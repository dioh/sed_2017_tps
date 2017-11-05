#ifndef _FplusStock1Flow1_H_
#define _FplusStock1Flow1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSSTOCK1FLOW1 "FplusStock1Flow1"

class FplusStock1Flow1 : public Atomic {
  public:
    
    FplusStock1Flow1(const string &name = FPLUSSTOCK1FLOW1 );
    virtual string className() const {  return FPLUSSTOCK1FLOW1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_growthCoefficient;
    const Port &in_stock1Integrator;
    // Output ports
    Port &out;

    // State variables
    double growthCoefficient;
    double stock1Integrator;
    //
    // Check set of state variables
    bool isSet_growthCoefficient;
    bool isSet_stock1Integrator;
    //
};

#endif