#ifndef _FplusLaborProductivitychgLaborProductivity_H_
#define _FplusLaborProductivitychgLaborProductivity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSLABORPRODUCTIVITYCHGLABORPRODUCTIVITY "FplusLaborProductivitychgLaborProductivity"

class FplusLaborProductivitychgLaborProductivity : public Atomic {
  public:
    
    FplusLaborProductivitychgLaborProductivity(const string &name = FPLUSLABORPRODUCTIVITYCHGLABORPRODUCTIVITY );
    virtual string className() const {  return FPLUSLABORPRODUCTIVITYCHGLABORPRODUCTIVITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_alphaa;
    const Port &in_laborProductivityIntegrator;
    // Output ports
    Port &out;

    // State variables
    double laborProductivityIntegrator;
    double alphaa;
    //
    // Check set of state variables
    bool isSet_laborProductivityIntegrator;
    bool isSet_alphaa;
    //
};

#endif