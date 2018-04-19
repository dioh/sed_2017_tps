#ifndef _TotReserves_H_
#define _TotReserves_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTRESERVES "TotReserves"

class TotReserves : public Atomic {
  public:
    
    TotReserves(const string &name = TOTRESERVES );
    virtual string className() const {  return TOTRESERVES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves;
    
    Port &out_port_TotReserves;

    double chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves;
    bool isSet_chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves;
    
    
};

#endif