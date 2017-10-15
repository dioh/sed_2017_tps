#ifndef _Shock2_H_
#define _Shock2_H_

#include <random>
#include <string>
#include <vector>

#include "atomic.h"
#include "VTime.h"

#define SHOCK2 "Shock2"

class Shock2 : public Atomic {
  public:
    
    Shock2(const string &name = SHOCK2 );
    virtual string className() const {  return SHOCK2 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    // Output ports
    Port &out50, &out34, &out84, &out33, &out11, &out73, &out64, &out21, &out30, &out22;

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif