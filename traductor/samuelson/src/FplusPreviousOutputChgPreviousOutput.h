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
    const Port &in_tIMESTEP2;
    // Output ports
    Port &out;

    // State variables
    double tIMESTEP2;
    double output;
    double previousoutputIntegrator;
    //
    // Check set of state variables
    bool isSet_tIMESTEP2;
    bool isSet_output;
    bool isSet_previousoutputIntegrator;
    //
};

#endif