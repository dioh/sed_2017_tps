#ifndef _chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons_H_
#define _chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGDEPCONS_DEPCONSDEVS_BASIC_COUPLED_DEPCONS "chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons"


class chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons : public Atomic {
  public:
    
    chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons(const string &name = CHGDEPCONS_DEPCONSDEVS_BASIC_COUPLED_DEPCONS );
    virtual string className() const {  return CHGDEPCONS_DEPCONSDEVS_BASIC_COUPLED_DEPCONS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Lend;
    const Port &in_port_InvBuy;
    const Port &in_port_ConsW;
    const Port &in_port_ConstantBuy;
    const Port &in_port_WagesC;
    const Port &in_port_Repay;
    const Port &in_port_Interest;
    const Port &in_port_ConsB;
    const Port &in_port_IntFee;
    Port &out_port_chgDepCons_DepCons;
    
    double Lend;
    double InvBuy;
    double ConsW;
    double ConstantBuy;
    double WagesC;
    double Repay;
    double Interest;
    double ConsB;
    double IntFee;
    bool isSet_Lend;
    bool isSet_InvBuy;
    bool isSet_ConsW;
    bool isSet_ConstantBuy;
    bool isSet_WagesC;
    bool isSet_Repay;
    bool isSet_Interest;
    bool isSet_ConsB;
    bool isSet_IntFee;
};

#endif