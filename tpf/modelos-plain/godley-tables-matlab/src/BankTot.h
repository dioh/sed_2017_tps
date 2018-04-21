#ifndef _BankTot_H_
#define _BankTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define BANKTOT "BankTot"

class BankTot : public Atomic {
  public:
    
    BankTot(const string &name = BANKTOT );
    virtual string className() const {  return BANKTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgBankPlus;
    Port &out;
    

    double val_chgBankPlus;
    bool isSet_val_chgBankPlus;
    
    
};

#endif