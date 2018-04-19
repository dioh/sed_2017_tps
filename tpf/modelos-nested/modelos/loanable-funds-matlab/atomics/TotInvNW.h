#ifndef _TotInvNW_H_
#define _TotInvNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTINVNW "TotInvNW"

class TotInvNW : public Atomic {
  public:
    
    TotInvNW(const string &name = TOTINVNW );
    virtual string className() const {  return TOTINVNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW;
    
    Port &out_port_TotInvNW;

    double chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW;
    bool isSet_chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW;
    
    
};

#endif