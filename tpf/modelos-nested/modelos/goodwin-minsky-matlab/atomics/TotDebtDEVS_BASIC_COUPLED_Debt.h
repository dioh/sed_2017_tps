#ifndef _TotDebtDEVS_BASIC_COUPLED_Debt_H_
#define _TotDebtDEVS_BASIC_COUPLED_Debt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTDEBTDEVS_BASIC_COUPLED_DEBT "TotDebtDEVS_BASIC_COUPLED_Debt"

class TotDebtDEVS_BASIC_COUPLED_Debt : public Atomic {
  public:
    
    TotDebtDEVS_BASIC_COUPLED_Debt(const string &name = TOTDEBTDEVS_BASIC_COUPLED_DEBT );
    virtual string className() const {  return TOTDEBTDEVS_BASIC_COUPLED_DEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgDebt_Debt;
    
    Port &out_port_TotDebt;

    double chgDebt_Debt;
    bool isSet_chgDebt_Debt;
    
    
};

#endif