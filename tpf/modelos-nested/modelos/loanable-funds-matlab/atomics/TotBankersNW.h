#ifndef _TotBankersNW_H_
#define _TotBankersNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTBANKERSNW "TotBankersNW"

class TotBankersNW : public Atomic {
  public:
    
    TotBankersNW(const string &name = TOTBANKERSNW );
    virtual string className() const {  return TOTBANKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW;
    
    Port &out_port_TotBankersNW;

    double chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW;
    bool isSet_chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW;
    
    
};

#endif