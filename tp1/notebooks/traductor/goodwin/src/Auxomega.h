#ifndef _Auxomega_H_
#define _Auxomega_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXOMEGA "Auxomega"


class Auxomega : public Atomic {
  public:
    
    Auxomega(const string &name = AUXOMEGA );
    virtual string className() const {  return AUXOMEGA ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_wages;
    const Port &in_output;
    // Output ports
    Port &out;

    // State variables
    double output;
    double wages;
    //
    // Check set of state variables
    bool isSet_output;
    bool isSet_wages;
    //
};

#endif