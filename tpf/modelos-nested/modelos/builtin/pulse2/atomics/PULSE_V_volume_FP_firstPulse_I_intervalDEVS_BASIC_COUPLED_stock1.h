#ifndef _PULSE_V_VOLUME_FP_FIRSTPULSE_I_INTERVALDEVS_BASIC_COUPLED_STOCK1_H_
#define _PULSE_V_VOLUME_FP_FIRSTPULSE_I_INTERVALDEVS_BASIC_COUPLED_STOCK1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PULSE_V_VOLUME_FP_FIRSTPULSE_I_INTERVALDEVS_BASIC_COUPLED_STOCK1 "PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1"


class PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1(const string &name = PULSE_V_VOLUME_FP_FIRSTPULSE_I_INTERVALDEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return PULSE_V_VOLUME_FP_FIRSTPULSE_I_INTERVALDEVS_BASIC_COUPLED_STOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &start;
    const Port &stop;
    Port &out;

    VTime frequency_time;
    bool on;

    std::uniform_int_distribution<int> dist;
    std::mt19937 rng;

    // Agregados
    
    Port &out_port_PULSE_V_volume_FP_firstPulse_I_interval;
    };

#endif