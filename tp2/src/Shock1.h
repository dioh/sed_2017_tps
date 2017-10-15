#ifndef _Shock1_H_
#define _Shock1_H_

#include <random>
#include <string>
#include <vector>

#include "atomic.h"
#include "VTime.h"

#define SHOCK1 "Shock1"

class Shock1 : public Atomic {
  public:
    
    Shock1(const string &name = SHOCK1 );
    virtual string className() const {  return SHOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    // Output ports
    Port &out02, &out74, &out41, &out43, &out90, &out24, &out94, &out40, &out42, &out70;

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif