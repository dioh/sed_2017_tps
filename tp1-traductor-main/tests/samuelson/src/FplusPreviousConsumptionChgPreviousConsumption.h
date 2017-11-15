#ifndef _FplusPreviousConsumptionChgPreviousConsumption_H_
#define _FplusPreviousConsumptionChgPreviousConsumption_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPREVIOUSCONSUMPTIONCHGPREVIOUSCONSUMPTION "FplusPreviousConsumptionChgPreviousConsumption"

class FplusPreviousConsumptionChgPreviousConsumption : public Atomic {
  public:
    
    FplusPreviousConsumptionChgPreviousConsumption(const string &name = FPLUSPREVIOUSCONSUMPTIONCHGPREVIOUSCONSUMPTION );
    virtual string className() const {  return FPLUSPREVIOUSCONSUMPTIONCHGPREVIOUSCONSUMPTION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_consumption;
    const Port &in_previousconsumptionIntegrator;
    const Port &in_tIMESTEP;
    // Output ports
    Port &out;

    // State variables
    double tIMESTEP;
    double previousconsumptionIntegrator;
    double consumption;
    //
    // Check set of state variables
    bool isSet_tIMESTEP;
    bool isSet_previousconsumptionIntegrator;
    bool isSet_consumption;
    //
};

#endif