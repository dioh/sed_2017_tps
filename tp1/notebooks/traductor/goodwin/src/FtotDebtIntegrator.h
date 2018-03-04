#ifndef _FtotDebtIntegrator_H_
#define _FtotDebtIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTDEBTINTEGRATOR "FtotDebtIntegrator"

class FtotDebtIntegrator : public Atomic {
  public:
    
    FtotDebtIntegrator(const string &name = FTOTDEBTINTEGRATOR );
    virtual string className() const {  return FTOTDEBTINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgDebt;
    Port &out;
    

    double val_inPlus_chgDebt;
    bool isSet_val_inPlus_chgDebt;
    
};

#endif