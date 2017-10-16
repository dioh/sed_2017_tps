#ifndef _Shocker_H_
#define _Shocker_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define SHOCKER "Shocker"

class Shocker : public Atomic {
  public:
    
    Shocker(const string &name = SHOCKER );
    virtual string className() const {  return SHOCKER ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in;
    // Output ports
    Port &out0, &out1, &out2, &out3, &out4, &out5, &out6, &out7, &out8, &out9, &out10, &out11, &out12, &out13, &out14, &out15, &out16, &out17, &out18, &out19;

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif