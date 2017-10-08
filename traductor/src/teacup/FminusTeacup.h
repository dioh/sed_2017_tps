#ifndef _FminusTeacup_H_
#define _FminusTeacup_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUSTEACUP "FminusTeacup"

class FminusTeacup : public Atomic {
  public:
    
    FminusTeacup(const string &name = FMINUSTEACUP );
    virtual string className() const {  return FMINUSTEACUP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inTeacupTemperature;
    const Port &inCharacteristicTime;
    const Port &inRoomTemperature;
    // Output ports
    Port &out;

    // State variables
    double teacupTemperature;
    double characteristicTime;
    double roomTemperature;
    //
    // Check set of state variables
    bool isSetTeacupTemperature;
    bool isSetCharacteristicTime;
    bool isSetRoomTemperature;
    //
};

#endif