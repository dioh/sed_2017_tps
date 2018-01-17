#ifndef _HeatLossToRoomPlus_H_
#define _HeatLossToRoomPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define HEATLOSSTOROOMPLUS "HeatLossToRoomPlus"


class HeatLossToRoomPlus : public Atomic {
  public:
    
    HeatLossToRoomPlus(const string &name = HEATLOSSTOROOMPLUS );
    virtual string className() const {  return HEATLOSSTOROOMPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &TemperatureValue;
    const Port &RoomTemperature;
    const Port &CharacteristicTime;
    Port &out;
    

    double val_TemperatureValue;
    double val_RoomTemperature;
    double val_CharacteristicTime;
    bool isSet_val_TemperatureValue;
    bool isSet_val_RoomTemperature;
    bool isSet_val_CharacteristicTime;
    
};

#endif