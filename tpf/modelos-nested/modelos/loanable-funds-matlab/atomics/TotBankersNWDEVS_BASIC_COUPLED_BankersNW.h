#ifndef _TotBankersNWDEVS_BASIC_COUPLED_BankersNW_H_
#define _TotBankersNWDEVS_BASIC_COUPLED_BankersNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTBANKERSNWDEVS_BASIC_COUPLED_BANKERSNW "TotBankersNWDEVS_BASIC_COUPLED_BankersNW"

class TotBankersNWDEVS_BASIC_COUPLED_BankersNW : public Atomic {
  public:
    
    TotBankersNWDEVS_BASIC_COUPLED_BankersNW(const string &name = TOTBANKERSNWDEVS_BASIC_COUPLED_BANKERSNW );
    virtual string className() const {  return TOTBANKERSNWDEVS_BASIC_COUPLED_BANKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgBankersNW_BankersNW;
    
    Port &out_port_TotBankersNW;

    double chgBankersNW_BankersNW;
    bool isSet_chgBankersNW_BankersNW;
    
    
};

#endif