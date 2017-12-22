#ifndef _TemperatureValueTot_H_
#define _TemperatureValueTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TEMPERATUREVALUETOT "TemperatureValueTot"

class TemperatureValueTot : public Atomic {
  public:
    
    TemperatureValueTot(const string &name = TEMPERATUREVALUETOT );
    virtual string className() const {  return TEMPERATUREVALUETOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &HeatLossToRoomMinus;
    Port &out;
    

    double val_HeatLossToRoomMinus;
    
    bool isSet_val_HeatLossToRoomMinus;
    
};

#endif