#ifndef _PULSE_V_COMBINER_FP_10_I_50_FLOW1DEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK_H_
#define _PULSE_V_COMBINER_FP_10_I_50_FLOW1DEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PULSE_V_COMBINER_FP_10_I_50_FLOW1DEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK "PULSE_V_combiner_FP_10_I_50_Flow1DEVS_BASIC_COUPLED_PreySubSubModelStock"


class PULSE_V_combiner_FP_10_I_50_Flow1DEVS_BASIC_COUPLED_PreySubSubModelStock : public Atomic {
  public:
    
    PULSE_V_combiner_FP_10_I_50_Flow1DEVS_BASIC_COUPLED_PreySubSubModelStock(const string &name = PULSE_V_COMBINER_FP_10_I_50_FLOW1DEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK );
    virtual string className() const {  return PULSE_V_COMBINER_FP_10_I_50_FLOW1DEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK ;}
  
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
    
    Port &out_port_PULSE_V_combiner_FP_10_I_50_Flow1;
    };

#endif