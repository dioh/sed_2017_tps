#ifndef _HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue_H_
#define _HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define HEATLOSSTOROOM_TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE "HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue"


class HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue : public Atomic {
  public:
    
    HeatLossToRoom_TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(const string &name = HEATLOSSTOROOM_TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE );
    virtual string className() const {  return HEATLOSSTOROOM_TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &TemperatureValue;
    const Port &RoomTemperature;
    const Port &CharacteristicTime;
    Port &HeatLossToRoom_TemperatureValue;
    
    double TemperatureValue;
    double RoomTemperature;
    double CharacteristicTime;
    bool isSet_TemperatureValue;
    bool isSet_RoomTemperature;
    bool isSet_CharacteristicTime;
};

#endif