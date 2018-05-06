#ifndef _PULSE_V_1_FP_1_I_1_PARAMEDEVS_COUPLED_TOP_H_
#define _PULSE_V_1_FP_1_I_1_PARAMEDEVS_COUPLED_TOP_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PULSE_V_1_FP_1_I_1_PARAMEDEVS_COUPLED_TOP "PULSE_V_1_FP_1_I_1_paramEDEVS_COUPLED_top"


class PULSE_V_1_FP_1_I_1_paramEDEVS_COUPLED_top : public Atomic {
  public:
    
    PULSE_V_1_FP_1_I_1_paramEDEVS_COUPLED_top(const string &name = PULSE_V_1_FP_1_I_1_PARAMEDEVS_COUPLED_TOP );
    virtual string className() const {  return PULSE_V_1_FP_1_I_1_PARAMEDEVS_COUPLED_TOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_start;
    const Port &stop;
    Port &out;

    VTime frequency_time;
    bool on;

    std::uniform_int_distribution<int> dist;
    std::mt19937 rng;

    // Agregados
    const Port &in_port_volume;
    bool isSet_in_port_volume = false;
    float volume;
    
    Port &out_port_PULSE_V_1_FP_1_I_1_paramE;
    };

#endif