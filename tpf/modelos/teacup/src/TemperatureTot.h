#ifndef _TemperatureTot_H_
#define _TemperatureTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TEMPERATURETOT "TemperatureTot"

class TemperatureTot : public Atomic {
  public:
    
    TemperatureTot(const string &name = TEMPERATURETOT );
    virtual string className() const {  return TEMPERATURETOT ;}
  
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