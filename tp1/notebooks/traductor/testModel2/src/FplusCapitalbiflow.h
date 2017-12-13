#ifndef _FplusCapitalbiflow_H_
#define _FplusCapitalbiflow_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSCAPITALBIFLOW "FplusCapitalbiflow"

class FplusCapitalbiflow : public Atomic {
  public:
    
    FplusCapitalbiflow(const string &name = FPLUSCAPITALBIFLOW );
    virtual string className() const {  return FPLUSCAPITALBIFLOW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_investmentIntegrator;
    const Port &in_capitalIntegrator;
    // Output ports
    Port &out;

    // State variables
    double investmentIntegrator;
    double capitalIntegrator;
    //
    // Check set of state variables
    bool isSet_investmentIntegrator;
    bool isSet_capitalIntegrator;
    //
};

#endif