#ifndef _PULSE_H_
#define _PULSE_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PULSE "Pulse"


class Pulse : public Atomic {
  public:
    
    Pulse(const string &name = PULSE );
    virtual string className() const {  return PULSE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &start;
    const Port &stop;
    Port &out;

    VTime frequency_time;
    bool on;

    std::uniform_int_distribution<int> dist;
    std::mt19937 rng;
};

#endif
