#ifndef _Fminus_H_
#define _Fminus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FMINUS "Fminus"

class Fminus : public Atomic {
  public:
    
    Fminus(const string &name = FMINUS );
    virtual string className() const {  return FMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inTeacupTemperature;
    const Port &inRoomTemperature, &inCharacteristicTime;
    Port &out;

    double teacupTemperature;
    bool isSetTeacupTemperature;

    double roomTemperature, characteristicTime;
    bool isSetRoomTemperature, isSetCharacteristicTime;
};

#endif
