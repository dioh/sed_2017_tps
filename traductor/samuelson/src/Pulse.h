#ifndef _Pulse_H_
#define _Pulse_H_

#include "atomic.h"
#include "VTime.h"

#define PULSE "Pulse"

class Pulse : public Atomic {
  public:
    
    Pulse(const string &name = "Pulse" );
    virtual string className() const {  return "Pulse" ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &start, &stop;
    const Port &in_hours, &in_minutes, &in_seconds, &in_milliseconds;
    const Port &in_value;
    Port &out;

    bool on;
    float value;

    VTime frequency_time;
    float hours, minutes, seconds, milliseconds;
    bool isSetHours, isSetMinutes, isSetSeconds, isSetMilliseconds;
};

#endif
