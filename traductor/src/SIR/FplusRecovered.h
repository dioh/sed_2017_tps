#ifndef _FplusRecovered_H_
#define _FplusRecovered_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSRECOVERED "FplusRecovered"

class FplusRecovered : public Atomic {
  public:
    
    FplusRecovered(const string &name = FPLUSRECOVERED );
    virtual string className() const {  return FPLUSRECOVERED ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &inInfected;
    const Port &inDuration;
    // Output ports
    Port &out;

    // State variables
    double infected;
    double duration;
    //
    // Check set of state variables
    bool isSetInfected;
    bool isSetDuration;
    //
};

#endif