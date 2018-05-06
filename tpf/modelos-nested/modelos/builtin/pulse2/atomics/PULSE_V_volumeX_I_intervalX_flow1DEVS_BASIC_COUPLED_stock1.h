#ifndef _PULSE_V_VOLUMEX_I_INTERVALX_FLOW1DEVS_BASIC_COUPLED_STOCK1_H_
#define _PULSE_V_VOLUMEX_I_INTERVALX_FLOW1DEVS_BASIC_COUPLED_STOCK1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PULSE_V_VOLUMEX_I_INTERVALX_FLOW1DEVS_BASIC_COUPLED_STOCK1 "PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1"


class PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1(const string &name = PULSE_V_VOLUMEX_I_INTERVALX_FLOW1DEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return PULSE_V_VOLUMEX_I_INTERVALX_FLOW1DEVS_BASIC_COUPLED_STOCK1 ;}
  
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

    // Agregados (volume + iterval)
    // TODO : volume y interval tienen que venir con el nombre de la variable + a que variable corresponde (volume o interval)
    const Port &in_port_volumeX;
    float volumeX;
    bool isSet_volume;
    const Port &in_port_intervalX;
    float intervalX;
    bool isSet_interval;
    
    Port &out_port_PULSE_V_volumeX_I_intervalX_flow1;
    };

#endif