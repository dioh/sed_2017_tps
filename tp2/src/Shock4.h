#ifndef _Shock4_H_
#define _Shock4_H_

#include <random>
#include <string>
#include <vector>

#include "atomic.h"
#include "VTime.h"

#define SHOCK4 "Shock4"

class Shock4 : public Atomic {
  public:
    
    Shock4(const string &name = SHOCK4 );
    virtual string className() const {  return SHOCK4 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    // Output ports
    Port &out72, &out32, &out14, &out60, &out62, &out12, &out82, &out71, &out53, &out51;

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif