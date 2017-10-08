#ifndef _CteRoomTemperature_H_
#define _CteRoomTemperature_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CTEROOMTEMPERATURE "CteRoomTemperature"


class CteRoomTemperature : public Atomic {
  public:
    
    CteRoomTemperature(const string &name = CTEROOMTEMPERATURE );
    virtual string className() const {  return CTEROOMTEMPERATURE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inVal;
    Port &out;

    double val;
};

#endif
