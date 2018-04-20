#ifndef _flow1_stock1DEVS_BASIC_COUPLED_stock1_H_
#define _flow1_stock1DEVS_BASIC_COUPLED_stock1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FLOW1_STOCK1DEVS_BASIC_COUPLED_STOCK1 "flow1_stock1DEVS_BASIC_COUPLED_stock1"


class flow1_stock1DEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    flow1_stock1DEVS_BASIC_COUPLED_stock1(const string &name = FLOW1_STOCK1DEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return FLOW1_STOCK1DEVS_BASIC_COUPLED_STOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_stock1;
    const Port &in_port_PULSE_V_volume_FP_firstPulse_I_interval;
    Port &out_port_flow1_stock1;
    
    double stock1;
    double PULSE_V_volume_FP_firstPulse_I_interval;
    bool isSet_stock1;
    bool isSet_PULSE_V_volume_FP_firstPulse_I_interval;
};

#endif