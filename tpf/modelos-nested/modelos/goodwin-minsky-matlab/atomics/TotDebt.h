#ifndef _TotDebt_H_
#define _TotDebt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTDEBT "TotDebt"

class TotDebt : public Atomic {
  public:
    
    TotDebt(const string &name = TOTDEBT );
    virtual string className() const {  return TOTDEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgDebt_DebtDEVS_BASIC_COUPLED_Debt;
    
    Port &out_port_TotDebt;

    double chgDebt_DebtDEVS_BASIC_COUPLED_Debt;
    bool isSet_chgDebt_DebtDEVS_BASIC_COUPLED_Debt;
    
    
};

#endif