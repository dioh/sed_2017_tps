#ifndef _FplusDebtchgDebt_H_
#define _FplusDebtchgDebt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSDEBTCHGDEBT "FplusDebtchgDebt"

class FplusDebtchgDebt : public Atomic {
  public:
    
    FplusDebtchgDebt(const string &name = FPLUSDEBTCHGDEBT );
    virtual string className() const {  return FPLUSDEBTCHGDEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_investmentGross;
    // Output ports
    Port &out;

    // State variables
    double investmentGross;
    //
    // Check set of state variables
    bool isSet_investmentGross;
    //
};

#endif