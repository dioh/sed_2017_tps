#ifndef _FminusCapitalbiflow_H_
#define _FminusCapitalbiflow_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSCAPITALBIFLOW "FminusCapitalbiflow"

class FminusCapitalbiflow : public Atomic {
  public:
    
    FminusCapitalbiflow(const string &name = FMINUSCAPITALBIFLOW );
    virtual string className() const {  return FMINUSCAPITALBIFLOW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_capitalIntegrator;
    const Port &in_investmentIntegrator;
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