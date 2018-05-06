#ifndef _flow2_stock1DEVS_BASIC_COUPLED_stock1_H_
#define _flow2_stock1DEVS_BASIC_COUPLED_stock1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FLOW2_STOCK1DEVS_BASIC_COUPLED_STOCK1 "flow2_stock1DEVS_BASIC_COUPLED_stock1"


class flow2_stock1DEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    flow2_stock1DEVS_BASIC_COUPLED_stock1(const string &name = FLOW2_STOCK1DEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return FLOW2_STOCK1DEVS_BASIC_COUPLED_STOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_PULSE_V_volume_I_interval_flow2;
    Port &out_port_flow2_stock1;
    
    double PULSE_V_volume_I_interval_flow2;
    bool isSet_PULSE_V_volume_I_interval_flow2;
};

#endif