#ifndef _chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW_H_
#define _chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGBANKERSNW_BANKERSNWDEVS_BASIC_COUPLED_BANKERSNW "chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW"


class chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW : public Atomic {
  public:
    
    chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW(const string &name = CHGBANKERSNW_BANKERSNWDEVS_BASIC_COUPLED_BANKERSNW );
    virtual string className() const {  return CHGBANKERSNW_BANKERSNWDEVS_BASIC_COUPLED_BANKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_ConsB;
    const Port &in_port_IntFee;
    Port &out_port_chgBankersNW_BankersNW;
    
    double ConsB;
    double IntFee;
    bool isSet_ConsB;
    bool isSet_IntFee;
};

#endif