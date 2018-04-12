#ifndef _chgCapital_CapitalDEVS_BASIC_COUPLED_Capital_H_
#define _chgCapital_CapitalDEVS_BASIC_COUPLED_Capital_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGCAPITAL_CAPITALDEVS_BASIC_COUPLED_CAPITAL "chgCapital_CapitalDEVS_BASIC_COUPLED_Capital"


class chgCapital_CapitalDEVS_BASIC_COUPLED_Capital : public Atomic {
  public:
    
    chgCapital_CapitalDEVS_BASIC_COUPLED_Capital(const string &name = CHGCAPITAL_CAPITALDEVS_BASIC_COUPLED_CAPITAL );
    virtual string className() const {  return CHGCAPITAL_CAPITALDEVS_BASIC_COUPLED_CAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_InvestmentNetReal;
    Port &out_port_chgCapital_Capital;
    
    double InvestmentNetReal;
    bool isSet_InvestmentNetReal;
};

#endif