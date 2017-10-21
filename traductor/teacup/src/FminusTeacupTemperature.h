#ifndef _FminusTeacupTemperature_H_
#define _FminusTeacupTemperature_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSTEACUPTEMPERATURE "FminusTeacupTemperature"

class FminusTeacupTemperature : public Atomic {
  public:
    
    FminusTeacupTemperature(const string &name = FMINUSTEACUPTEMPERATURE );
    virtual string className() const {  return FMINUSTEACUPTEMPERATURE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inTeacupTemperatureIntegrator;
    const Port &inRoomTemperature;
    const Port &inCharacteristicTime;
    // Output ports
    Port &out;

    // State variables
    double teacupTemperatureIntegrator;
    double roomTemperature;
    double characteristicTime;
    //
    // Check set of state variables
    bool isSetTeacupTemperatureIntegrator;
    bool isSetRoomTemperature;
    bool isSetCharacteristicTime;
    //
};

#endif