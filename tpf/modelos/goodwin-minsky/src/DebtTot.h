#ifndef _DebtTot_H_
#define _DebtTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define DEBTTOT "DebtTot"

class DebtTot : public Atomic {
  public:
    
    DebtTot(const string &name = DEBTTOT );
    virtual string className() const {  return DEBTTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgDebtPlus;
    Port &out;
    

    double val_chgDebtPlus;
    bool isSet_val_chgDebtPlus;
    
    
};

#endif