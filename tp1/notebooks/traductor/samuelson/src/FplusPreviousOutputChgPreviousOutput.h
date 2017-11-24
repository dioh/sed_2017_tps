#ifndef _FplusPreviousOutputChgPreviousOutput_H_
#define _FplusPreviousOutputChgPreviousOutput_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPREVIOUSOUTPUTCHGPREVIOUSOUTPUT "FplusPreviousOutputChgPreviousOutput"

class FplusPreviousOutputChgPreviousOutput : public Atomic {
  public:
    
    FplusPreviousOutputChgPreviousOutput(const string &name = FPLUSPREVIOUSOUTPUTCHGPREVIOUSOUTPUT );
    virtual string className() const {  return FPLUSPREVIOUSOUTPUTCHGPREVIOUSOUTPUT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_output;
    const Port &in_previousoutputIntegrator;
    const Port &in_twounitTimestep;
    // Output ports
    Port &out;

    // State variables
    double output;
    double twounitTimestep;
    double previousoutputIntegrator;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_twounitTimestep;
    bool isSet_previousoutputIntegrator;
    //
};

#endif