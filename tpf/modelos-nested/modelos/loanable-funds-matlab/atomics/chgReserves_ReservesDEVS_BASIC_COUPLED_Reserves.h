#ifndef _chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves_H_
#define _chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGRESERVES_RESERVESDEVS_BASIC_COUPLED_RESERVES "chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves"


class chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves : public Atomic {
  public:
    
    chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves(const string &name = CHGRESERVES_RESERVESDEVS_BASIC_COUPLED_RESERVES );
    virtual string className() const {  return CHGRESERVES_RESERVESDEVS_BASIC_COUPLED_RESERVES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    Port &out_port_chgReserves_Reserves;
    
};

#endif