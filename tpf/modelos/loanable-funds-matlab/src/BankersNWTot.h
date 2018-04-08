#ifndef _BankersNWTot_H_
#define _BankersNWTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define BANKERSNWTOT "BankersNWTot"

class BankersNWTot : public Atomic {
  public:
    
    BankersNWTot(const string &name = BANKERSNWTOT );
    virtual string className() const {  return BANKERSNWTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgBankersNWPlus;
    Port &out;
    

    double val_chgBankersNWPlus;
    bool isSet_val_chgBankersNWPlus;
    
    
};

#endif