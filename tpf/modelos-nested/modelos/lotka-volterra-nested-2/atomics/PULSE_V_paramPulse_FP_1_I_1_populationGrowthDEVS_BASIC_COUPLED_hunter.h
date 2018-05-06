#ifndef _PULSE_V_PARAMPULSE_FP_1_I_1_POPULATIONGROWTHDEVS_BASIC_COUPLED_HUNTER_H_
#define _PULSE_V_PARAMPULSE_FP_1_I_1_POPULATIONGROWTHDEVS_BASIC_COUPLED_HUNTER_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PULSE_V_PARAMPULSE_FP_1_I_1_POPULATIONGROWTHDEVS_BASIC_COUPLED_HUNTER "PULSE_V_paramPulse_FP_1_I_1_populationGrowthDEVS_BASIC_COUPLED_hunter"


class PULSE_V_paramPulse_FP_1_I_1_populationGrowthDEVS_BASIC_COUPLED_hunter : public Atomic {
  public:
    
    PULSE_V_paramPulse_FP_1_I_1_populationGrowthDEVS_BASIC_COUPLED_hunter(const string &name = PULSE_V_PARAMPULSE_FP_1_I_1_POPULATIONGROWTHDEVS_BASIC_COUPLED_HUNTER );
    virtual string className() const {  return PULSE_V_PARAMPULSE_FP_1_I_1_POPULATIONGROWTHDEVS_BASIC_COUPLED_HUNTER ;}
  
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
    
    Port &out_port_PULSE_V_paramPulse_FP_1_I_1_populationGrowth;
    };

#endif