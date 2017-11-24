#ifndef _Auxconsumption_H_
#define _Auxconsumption_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXCONSUMPTION "Auxconsumption"


class Auxconsumption : public Atomic {
  public:
    
    Auxconsumption(const string &name = AUXCONSUMPTION );
    virtual string className() const {  return AUXCONSUMPTION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_marginalPropensitytoConsumealpha;
    const Port &in_prevOutptIntegrator;
    // Output ports
    Port &out;

    // State variables
    double prevOutptIntegrator;
    double marginalPropensitytoConsumealpha;
    //
    // Check set of state variables
    bool isSet_prevOutptIntegrator;
    bool isSet_marginalPropensitytoConsumealpha;
    //
};

#endif