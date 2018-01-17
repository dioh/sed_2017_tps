#ifndef _HeatLossToRoomMinus_H_
#define _HeatLossToRoomMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define HEATLOSSTOROOMMINUS "HeatLossToRoomMinus"


class HeatLossToRoomMinus : public Atomic {
  public:
    
    HeatLossToRoomMinus(const string &name = HEATLOSSTOROOMMINUS );
    virtual string className() const {  return HEATLOSSTOROOMMINUS ;}
  
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