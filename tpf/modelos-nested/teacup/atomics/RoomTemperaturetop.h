#ifndef _RoomTemperaturetop_H_
#define _RoomTemperaturetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define ROOMTEMPERATURETOP "RoomTemperaturetop"


class RoomTemperaturetop : public Atomic {
  public:
    
    RoomTemperaturetop(const string &name = ROOMTEMPERATURETOP );
    virtual string className() const {  return ROOMTEMPERATURETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_RoomTemperature;
    
    Port &out_port_RoomTemperature;
    
    double RoomTemperature;
    };

#endif