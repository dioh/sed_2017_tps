#ifndef _TotTemperatureValue_H_
#define _TotTemperatureValue_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTTEMPERATUREVALUE "TotTemperatureValue"

class TotTemperatureValue : public Atomic {
  public:
    
    TotTemperatureValue(const string &name = TOTTEMPERATUREVALUE );
    virtual string className() const {  return TOTTEMPERATUREVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_minus_port_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue;
    
    Port &out_port_TotTemperatureValue;

    double HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue;
    
    bool isSet_HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue;
    
};

#endif