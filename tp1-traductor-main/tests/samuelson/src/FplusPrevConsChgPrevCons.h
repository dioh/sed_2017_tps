#ifndef _FplusPrevConsChgPrevCons_H_
#define _FplusPrevConsChgPrevCons_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FPLUSPREVCONSCHGPREVCONS "FplusPrevConsChgPrevCons"

class FplusPrevConsChgPrevCons : public Atomic {
  public:
    
    FplusPrevConsChgPrevCons(const string &name = FPLUSPREVCONSCHGPREVCONS );
    virtual string className() const {  return FPLUSPREVCONSCHGPREVCONS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_consumption;
    const Port &in_prevConsIntegrator;
    const Port &in_timestep;
    // Output ports
    Port &out;

    // State variables
    double consumption;
    double prevConsIntegrator;
    double timestep;
    //
    // Check set of state variables
    bool isSet_consumption;
    bool isSet_prevConsIntegrator;
    bool isSet_timestep;
    //
};

#endif