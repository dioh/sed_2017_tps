#ifndef _FplusCapitalchgCapital_H_
#define _FplusCapitalchgCapital_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSCAPITALCHGCAPITAL "FplusCapitalchgCapital"

class FplusCapitalchgCapital : public Atomic {
  public:
    
    FplusCapitalchgCapital(const string &name = FPLUSCAPITALCHGCAPITAL );
    virtual string className() const {  return FPLUSCAPITALCHGCAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_investmentNetReal;
    // Output ports
    Port &out;

    // State variables
    double investmentNetReal;
    //
    // Check set of state variables
    bool isSet_investmentNetReal;
    //
};

#endif