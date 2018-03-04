#ifndef _Auxlabor_H_
#define _Auxlabor_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXLABOR "Auxlabor"


class Auxlabor : public Atomic {
  public:
    
    Auxlabor(const string &name = AUXLABOR );
    virtual string className() const {  return AUXLABOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_output;
    const Port &in_laborProductivityIntegrator;
    // Output ports
    Port &out;

    // State variables
    double output;
    double laborProductivityIntegrator;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_laborProductivityIntegrator;
    //
};

#endif