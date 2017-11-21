#ifndef _FminusTeacupTemperatureHeatLosstoRoom_H_
#define _FminusTeacupTemperatureHeatLosstoRoom_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSTEACUPTEMPERATUREHEATLOSSTOROOM "FminusTeacupTemperatureHeatLosstoRoom"

class FminusTeacupTemperatureHeatLosstoRoom : public Atomic {
  public:
    
    FminusTeacupTemperatureHeatLosstoRoom(const string &name = FMINUSTEACUPTEMPERATUREHEATLOSSTOROOM );
    virtual string className() const {  return FMINUSTEACUPTEMPERATUREHEATLOSSTOROOM ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_teacupTemperatureIntegrator;
    const Port &in_roomTemperature;
    const Port &in_characteristicTime;
    // Output ports
    Port &out;

    // State variables
    double teacupTemperatureIntegrator;
    double roomTemperature;
    double characteristicTime;
    //
    // Check set of state variables
    bool isSet_teacupTemperatureIntegrator;
    bool isSet_roomTemperature;
    bool isSet_characteristicTime;
    //
};

#endif