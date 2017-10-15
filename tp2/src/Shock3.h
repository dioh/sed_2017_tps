#ifndef _Shock3_H_
#define _Shock3_H_

#include <random>
#include <string>
#include <vector>

#include "atomic.h"
#include "VTime.h"

#define SHOCK3 "Shock3"

class Shock3 : public Atomic {
  public:
    
    Shock3(const string &name = SHOCK3 );
    virtual string className() const {  return SHOCK3 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    // Output ports
    Port &out63, &out81, &out44, &out04, &out83, &out91, &out23, &out01, &out31, &out54;

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif