#ifndef _populationGrowth_hunterDEVS_BASIC_COUPLED_hunter_H_
#define _populationGrowth_hunterDEVS_BASIC_COUPLED_hunter_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define POPULATIONGROWTH_HUNTERDEVS_BASIC_COUPLED_HUNTER "populationGrowth_hunterDEVS_BASIC_COUPLED_hunter"


class populationGrowth_hunterDEVS_BASIC_COUPLED_hunter : public Atomic {
  public:
    
    populationGrowth_hunterDEVS_BASIC_COUPLED_hunter(const string &name = POPULATIONGROWTH_HUNTERDEVS_BASIC_COUPLED_HUNTER );
    virtual string className() const {  return POPULATIONGROWTH_HUNTERDEVS_BASIC_COUPLED_HUNTER ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_PULSE_V_paramPulse_FP_1_I_1;
    const Port &in_port_hunter;
    Port &out_port_populationGrowth_hunter;
    
    double PULSE_V_paramPulse_FP_1_I_1;
    double hunter;
    bool isSet_PULSE_V_paramPulse_FP_1_I_1;
    bool isSet_hunter;
};

#endif