#ifndef _CharacteristicTimetop_H_
#define _CharacteristicTimetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHARACTERISTICTIMETOP "CharacteristicTimetop"


class CharacteristicTimetop : public Atomic {
  public:
    
    CharacteristicTimetop(const string &name = CHARACTERISTICTIMETOP );
    virtual string className() const {  return CHARACTERISTICTIMETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_CharacteristicTime;
    
    Port &out_port_CharacteristicTime;
    
    double CharacteristicTime;
    };

#endif