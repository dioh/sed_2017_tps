#ifndef _chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW_H_
#define _chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGCONSNW_CONSNWDEVS_BASIC_COUPLED_CONSNW "chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW"


class chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW : public Atomic {
  public:
    
    chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW(const string &name = CHGCONSNW_CONSNWDEVS_BASIC_COUPLED_CONSNW );
    virtual string className() const {  return CHGCONSNW_CONSNWDEVS_BASIC_COUPLED_CONSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_InvBuy;
    const Port &in_port_ConsW;
    const Port &in_port_ConstantBuy;
    const Port &in_port_ConsB;
    const Port &in_port_IntFee;
    const Port &in_port_Interest;
    const Port &in_port_WagesC;
    Port &out_port_chgConsNW_ConsNW;
    
    double InvBuy;
    double ConsW;
    double ConstantBuy;
    double ConsB;
    double IntFee;
    double Interest;
    double WagesC;
    bool isSet_InvBuy;
    bool isSet_ConsW;
    bool isSet_ConstantBuy;
    bool isSet_ConsB;
    bool isSet_IntFee;
    bool isSet_Interest;
    bool isSet_WagesC;
};

#endif