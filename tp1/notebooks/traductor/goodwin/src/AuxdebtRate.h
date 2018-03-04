#ifndef _AuxdebtRate_H_
#define _AuxdebtRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXDEBTRATE "AuxdebtRate"


class AuxdebtRate : public Atomic {
  public:
    
    AuxdebtRate(const string &name = AUXDEBTRATE );
    virtual string className() const {  return AUXDEBTRATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_debtIntegrator;
    const Port &in_output;
    // Output ports
    Port &out;

    // State variables
    double output;
    double debtIntegrator;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_debtIntegrator;
    //
};

#endif