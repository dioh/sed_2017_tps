#ifndef _TotDepInvDEVS_BASIC_COUPLED_DepInv_H_
#define _TotDepInvDEVS_BASIC_COUPLED_DepInv_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTDEPINVDEVS_BASIC_COUPLED_DEPINV "TotDepInvDEVS_BASIC_COUPLED_DepInv"

class TotDepInvDEVS_BASIC_COUPLED_DepInv : public Atomic {
  public:
    
    TotDepInvDEVS_BASIC_COUPLED_DepInv(const string &name = TOTDEPINVDEVS_BASIC_COUPLED_DEPINV );
    virtual string className() const {  return TOTDEPINVDEVS_BASIC_COUPLED_DEPINV ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgDepInv_DepInv;
    
    Port &out_port_TotDepInv;

    double chgDepInv_DepInv;
    bool isSet_chgDepInv_DepInv;
    
    
};

#endif