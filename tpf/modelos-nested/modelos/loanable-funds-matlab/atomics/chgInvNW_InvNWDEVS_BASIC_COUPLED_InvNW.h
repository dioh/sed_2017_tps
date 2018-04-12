#ifndef _chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW_H_
#define _chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGINVNW_INVNWDEVS_BASIC_COUPLED_INVNW "chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW"


class chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW : public Atomic {
  public:
    
    chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW(const string &name = CHGINVNW_INVNWDEVS_BASIC_COUPLED_INVNW );
    virtual string className() const {  return CHGINVNW_INVNWDEVS_BASIC_COUPLED_INVNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_WagesI;
    const Port &in_port_InvBuy;
    const Port &in_port_Interest;
    const Port &in_port_ConstantBuy;
    Port &out_port_chgInvNW_InvNW;
    
    double WagesI;
    double InvBuy;
    double Interest;
    double ConstantBuy;
    bool isSet_WagesI;
    bool isSet_InvBuy;
    bool isSet_Interest;
    bool isSet_ConstantBuy;
};

#endif