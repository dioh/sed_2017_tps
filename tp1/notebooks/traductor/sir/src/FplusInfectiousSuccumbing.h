#ifndef _FplusInfectiousSuccumbing_H_
#define _FplusInfectiousSuccumbing_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSINFECTIOUSSUCCUMBING "FplusInfectiousSuccumbing"

class FplusInfectiousSuccumbing : public Atomic {
  public:
    
    FplusInfectiousSuccumbing(const string &name = FPLUSINFECTIOUSSUCCUMBING );
    virtual string className() const {  return FPLUSINFECTIOUSSUCCUMBING ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_susceptibleIntegrator;
    const Port &in_infectiousIntegrator;
    const Port &in_totalPopulation;
    const Port &in_contactInfectivity;
    // Output ports
    Port &out;

    // State variables
    double infectiousIntegrator;
    double totalPopulation;
    double contactInfectivity;
    double susceptibleIntegrator;
    //
    // Check set of state variables
    bool isSet_infectiousIntegrator;
    bool isSet_totalPopulation;
    bool isSet_contactInfectivity;
    bool isSet_susceptibleIntegrator;
    //
};

#endif