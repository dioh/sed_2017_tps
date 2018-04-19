#ifndef _TotDepInv_H_
#define _TotDepInv_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTDEPINV "TotDepInv"

class TotDepInv : public Atomic {
  public:
    
    TotDepInv(const string &name = TOTDEPINV );
    virtual string className() const {  return TOTDEPINV ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv;
    
    Port &out_port_TotDepInv;

    double chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv;
    bool isSet_chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv;
    
    
};

#endif