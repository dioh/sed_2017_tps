#ifndef _chgDebt_DebtDEVS_BASIC_COUPLED_Debt_H_
#define _chgDebt_DebtDEVS_BASIC_COUPLED_Debt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEBT_DEBTDEVS_BASIC_COUPLED_DEBT "chgDebt_DebtDEVS_BASIC_COUPLED_Debt"


class chgDebt_DebtDEVS_BASIC_COUPLED_Debt : public Atomic {
  public:
    
    chgDebt_DebtDEVS_BASIC_COUPLED_Debt(const string &name = CHGDEBT_DEBTDEVS_BASIC_COUPLED_DEBT );
    virtual string className() const {  return CHGDEBT_DEBTDEVS_BASIC_COUPLED_DEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_InvestmentGross;
    Port &out_port_chgDebt_Debt;
    
    double InvestmentGross;
    bool isSet_InvestmentGross;
};

#endif