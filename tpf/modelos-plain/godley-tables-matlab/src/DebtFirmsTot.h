#ifndef _DebtFirmsTot_H_
#define _DebtFirmsTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define DEBTFIRMSTOT "DebtFirmsTot"

class DebtFirmsTot : public Atomic {
  public:
    
    DebtFirmsTot(const string &name = DEBTFIRMSTOT );
    virtual string className() const {  return DEBTFIRMSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgDebtFirmsPlus;
    Port &out;
    

    double val_chgDebtFirmsPlus;
    bool isSet_val_chgDebtFirmsPlus;
    
    
};

#endif