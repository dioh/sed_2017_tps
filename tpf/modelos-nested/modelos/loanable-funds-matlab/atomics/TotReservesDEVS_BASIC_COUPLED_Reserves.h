#ifndef _TotReservesDEVS_BASIC_COUPLED_Reserves_H_
#define _TotReservesDEVS_BASIC_COUPLED_Reserves_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTRESERVESDEVS_BASIC_COUPLED_RESERVES "TotReservesDEVS_BASIC_COUPLED_Reserves"

class TotReservesDEVS_BASIC_COUPLED_Reserves : public Atomic {
  public:
    
    TotReservesDEVS_BASIC_COUPLED_Reserves(const string &name = TOTRESERVESDEVS_BASIC_COUPLED_RESERVES );
    virtual string className() const {  return TOTRESERVESDEVS_BASIC_COUPLED_RESERVES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgReserves_Reserves;
    
    Port &out_port_TotReserves;

    double chgReserves_Reserves;
    bool isSet_chgReserves_Reserves;
    
    
};

#endif