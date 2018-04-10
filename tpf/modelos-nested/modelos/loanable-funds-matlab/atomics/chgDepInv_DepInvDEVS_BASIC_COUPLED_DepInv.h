#ifndef _chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv_H_
#define _chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEPINV_DEPINVDEVS_BASIC_COUPLED_DEPINV "chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv"


class chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv : public Atomic {
  public:
    
    chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv(const string &name = CHGDEPINV_DEPINVDEVS_BASIC_COUPLED_DEPINV );
    virtual string className() const {  return CHGDEPINV_DEPINVDEVS_BASIC_COUPLED_DEPINV ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Repay;
    const Port &in_port_Interest;
    const Port &in_port_WagesI;
    const Port &in_port_Lend;
    const Port &in_port_InvBuy;
    const Port &in_port_ConstantBuy;
    Port &out_port_chgDepInv_DepInv;
    
    double Repay;
    double Interest;
    double WagesI;
    double Lend;
    double InvBuy;
    double ConstantBuy;
    bool isSet_Repay;
    bool isSet_Interest;
    bool isSet_WagesI;
    bool isSet_Lend;
    bool isSet_InvBuy;
    bool isSet_ConstantBuy;
};

#endif