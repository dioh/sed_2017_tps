#ifndef _Auxwages_H_
#define _Auxwages_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXWAGES "Auxwages"


class Auxwages : public Atomic {
  public:
    
    Auxwages(const string &name = AUXWAGES );
    virtual string className() const {  return AUXWAGES ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_wageRateIntegrator;
    const Port &in_labor;
    // Output ports
    Port &out;

    // State variables
    double wageRateIntegrator;
    double labor;
    //
    // Check set of state variables
    bool isSet_wageRateIntegrator;
    bool isSet_labor;
    //
};

#endif