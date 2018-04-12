#ifndef _TotInvNWDEVS_BASIC_COUPLED_InvNW_H_
#define _TotInvNWDEVS_BASIC_COUPLED_InvNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTINVNWDEVS_BASIC_COUPLED_INVNW "TotInvNWDEVS_BASIC_COUPLED_InvNW"

class TotInvNWDEVS_BASIC_COUPLED_InvNW : public Atomic {
  public:
    
    TotInvNWDEVS_BASIC_COUPLED_InvNW(const string &name = TOTINVNWDEVS_BASIC_COUPLED_INVNW );
    virtual string className() const {  return TOTINVNWDEVS_BASIC_COUPLED_INVNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgInvNW_InvNW;
    
    Port &out_port_TotInvNW;

    double chgInvNW_InvNW;
    bool isSet_chgInvNW_InvNW;
    
    
};

#endif