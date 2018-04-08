#ifndef _TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue_H_
#define _TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTTEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE "TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue"

class TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue : public Atomic {
  public:
    
    TotTemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(const string &name = TOTTEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE );
    virtual string className() const {  return TOTTEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &HeatLossToRoom_TemperatureValue;
    

    double HeatLossToRoom_TemperatureValue;
    
    bool isSet_HeatLossToRoom_TemperatureValue;
    
};

#endif