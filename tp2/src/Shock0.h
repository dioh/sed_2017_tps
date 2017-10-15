#ifndef _Shock0_H_
#define _Shock0_H_

#include <random>
#include <string>
#include <vector>

#include "atomic.h"
#include "VTime.h"

#define SHOCK0 "Shock0"

class Shock0 : public Atomic {
  public:
    
    Shock0(const string &name = SHOCK0 );
    virtual string className() const {  return SHOCK0 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    // Output ports
    Port &out61, &out93, &out03, &out80, &out13, &out00, &out20, &out52, &out10, &out92;

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif